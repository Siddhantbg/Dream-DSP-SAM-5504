#pragma once

#include "../AppState.h"
#include <JuceHeader.h>

class HostAudioEngine : public juce::AudioIODeviceCallback
{
public:
    HostAudioEngine();
    ~HostAudioEngine() override;

    void prepare (double sampleRate);
    void start();
    void stop();

    void setParameter (ParamId id, float normalised);
    void setChannelMute (int channelIndex, bool muted, float prevGain);

    double getSampleRate() const { return currentSampleRate; }

private:
    struct ChannelChain
    {
        juce::dsp::Gain<float> inputGain;
        std::array<juce::dsp::IIR::Filter<float>, 3> eqFilters;
        juce::dsp::Compressor<float> compressor;
        juce::dsp::DelayLine<float, juce::dsp::DelayLineInterpolationTypes::Linear> delayLine;
        juce::dsp::Gain<float> phaseGain;
        juce::dsp::Gain<float> outputGain;
        juce::SmoothedValue<float, juce::ValueSmoothingTypes::Linear> smoothedGain { 1.0f };
        float prevGain = 1.0f;
        bool muted = false;
    };

    void audioDeviceIOCallbackWithContext (const float* const* inputChannelData,
                                           int numInputChannels,
                                           float* const* outputChannelData,
                                           int numOutputChannels,
                                           int numSamples,
                                           const juce::AudioIODeviceCallbackContext& context) override;

    void audioDeviceAboutToStart (juce::AudioIODevice* device) override;
    void audioDeviceStopped() override;

    void updateEqBand (ChannelChain& chain, int band, float freqHz, float gainDb, float Q);
    ChannelChain& chainForParam (ParamId id);

    juce::AudioDeviceManager deviceManager;
    std::array<ChannelChain, 4> chains;
    double currentSampleRate = 48000.0;
    juce::dsp::Oscillator<float> testOsc;
    bool useTestTone = true;
};
