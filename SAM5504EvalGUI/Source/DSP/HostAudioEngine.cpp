#include "HostAudioEngine.h"

HostAudioEngine::HostAudioEngine()
{
    testOsc.initialise ([] (float x) { return std::sin (x); }, 128);
    testOsc.setFrequency (440.0f);
}

HostAudioEngine::~HostAudioEngine()
{
    stop();
}

void HostAudioEngine::prepare (const double sampleRate)
{
    currentSampleRate = sampleRate;
    testOsc.prepare ({ sampleRate, 512, 2 });

    juce::dsp::ProcessSpec spec;
    spec.sampleRate = sampleRate;
    spec.maximumBlockSize = 512;
    spec.numChannels = 1;

    for (auto& chain : chains)
    {
        chain.inputGain.prepare (spec);
        chain.outputGain.prepare (spec);
        chain.phaseGain.prepare (spec);
        chain.compressor.prepare (spec);
        chain.delayLine.prepare (spec);
        chain.delayLine.setMaximumDelayInSamples (static_cast<int> (sampleRate));
        chain.smoothedGain.reset (sampleRate, 0.05);
        chain.phaseGain.setGainLinear (0.0f);

        for (auto& f : chain.eqFilters)
        {
            f.prepare (spec);
            *f.coefficients = *juce::dsp::IIR::Coefficients<float>::makePeakFilter (
                sampleRate, 1000.0f, 0.707f, 1.0f);
        }

        chain.compressor.setThreshold (-24.0f);
        chain.compressor.setRatio (4.0f);
        chain.compressor.setAttack (10.0f);
        chain.compressor.setRelease (100.0f);
    }
}

void HostAudioEngine::start()
{
    deviceManager.initialiseWithDefaultDevices (0, 2);
    deviceManager.addAudioCallback (this);
}

void HostAudioEngine::stop()
{
    deviceManager.removeAudioCallback (this);
    deviceManager.closeAudioDevice();
}

void HostAudioEngine::setChannelMute (const int channelIndex, const bool muted, const float prevGain)
{
    if (channelIndex < 0 || channelIndex >= 4)
        return;

    auto& chain = chains[static_cast<size_t> (channelIndex)];

    if (muted)
    {
        chain.prevGain = chain.smoothedGain.getTargetValue();
        chain.muted = true;
        chain.smoothedGain.setTargetValue (0.0f);
    }
    else
    {
        chain.muted = false;
        chain.smoothedGain.setTargetValue (prevGain);
    }
}

void HostAudioEngine::setParameter (const ParamId id, const float normalised)
{
    auto& chain = chainForParam (id);
    const auto n = juce::jlimit (0.0f, 1.0f, normalised);

    switch (id)
    {
        case ParamId::Input_LeftGain:
        case ParamId::LSub_OutputGain:
        case ParamId::RSub_OutputGain:
        case ParamId::Input_RightGain:
            chain.smoothedGain.setTargetValue (n);
            chain.prevGain = n;
            break;

        case ParamId::LSub_CompThreshold:
        case ParamId::RSub_CompThreshold:
            chain.compressor.setThreshold (-60.0f + n * 60.0f);
            break;

        case ParamId::LMid_DelayTime:
        case ParamId::RMid_DelayTime:
            chain.delayLine.setDelay (static_cast<float> (currentSampleRate * (n * 0.5)));
            break;

        case ParamId::LMid_DelayGain:
        case ParamId::RMid_DelayGain:
            chain.phaseGain.setGainLinear (n);
            break;

        default:
            break;
    }
}

HostAudioEngine::ChannelChain& HostAudioEngine::chainForParam (const ParamId id)
{
    switch (id)
    {
        case ParamId::Input_LeftGain:
        case ParamId::LSub_OutputGain:
        case ParamId::LSub_CompThreshold:
            return chains[0];

        case ParamId::LMid_DelayTime:
        case ParamId::LMid_DelayGain:
            return chains[1];

        case ParamId::Input_RightGain:
        case ParamId::RSub_OutputGain:
        case ParamId::RSub_CompThreshold:
            return chains[2];

        case ParamId::RMid_DelayTime:
        case ParamId::RMid_DelayGain:
            return chains[3];

        default:
            return chains[0];
    }
}

void HostAudioEngine::updateEqBand (ChannelChain& chain, const int band, const float freqHz,
                                    const float gainDb, const float Q)
{
    if (band < 0 || band >= 3)
        return;

    *chain.eqFilters[static_cast<size_t> (band)].coefficients =
        *juce::dsp::IIR::Coefficients<float>::makePeakFilter (
            currentSampleRate, freqHz, Q, juce::Decibels::decibelsToGain (gainDb));
}

void HostAudioEngine::audioDeviceAboutToStart (juce::AudioIODevice* device)
{
    prepare (device->getCurrentSampleRate());
}

void HostAudioEngine::audioDeviceStopped()
{
}

void HostAudioEngine::audioDeviceIOCallbackWithContext (const float* const* inputChannelData,
                                                        int numInputChannels,
                                                        float* const* outputChannelData,
                                                        int numOutputChannels,
                                                        int numSamples,
                                                        const juce::AudioIODeviceCallbackContext&)
{
    juce::ignoreUnused (inputChannelData, numInputChannels);

    if (outputChannelData == nullptr || numOutputChannels < 1)
        return;

    juce::AudioBuffer<float> buffer (1, numSamples);

    for (int i = 0; i < numSamples; ++i)
    {
        float s = 0.0f;

        if (useTestTone)
            s = testOsc.processSample (0.0f) * 0.12f;

        buffer.setSample (0, i, s);
    }

    auto block = juce::dsp::AudioBlock<float> (buffer);
    auto& chain = chains[0];

    for (int i = 0; i < numSamples; ++i)
        buffer.setSample (0, i, buffer.getSample (0, i) * chain.smoothedGain.getNextValue());

    juce::dsp::ProcessContextReplacing<float> ctx (block);

    chain.inputGain.process (ctx);

    for (auto& eq : chain.eqFilters)
        eq.process (ctx);

    chain.compressor.process (ctx);
    chain.outputGain.process (ctx);

    for (int ch = 0; ch < numOutputChannels; ++ch)
    {
        if (outputChannelData[ch] == nullptr)
            continue;

        for (int i = 0; i < numSamples; ++i)
            outputChannelData[ch][i] = buffer.getSample (0, i);
    }
}
