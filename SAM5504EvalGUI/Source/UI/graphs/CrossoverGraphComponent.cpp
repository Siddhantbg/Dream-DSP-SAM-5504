#include "CrossoverGraphComponent.h"

CrossoverGraphComponent::CrossoverGraphComponent()
{
    hpfL = juce::dsp::IIR::Coefficients<float>::makeHighPass (sampleRate, crossoverHz);
    lpfL = juce::dsp::IIR::Coefficients<float>::makeLowPass (sampleRate, crossoverHz);
    hpfR = hpfL;
    lpfR = lpfL;
}

void CrossoverGraphComponent::setCrossoverFrequency (const float hz)
{
    crossoverHz = hz;
    hpfL = juce::dsp::IIR::Coefficients<float>::makeHighPass (sampleRate, crossoverHz);
    lpfL = juce::dsp::IIR::Coefficients<float>::makeLowPass (sampleRate, crossoverHz);

    if (mode == Mode::InputDualChannel)
    {
        hpfR = hpfL;
        lpfR = lpfL;
    }

    repaint();
}

void CrossoverGraphComponent::setHPFCoefficients (juce::dsp::IIR::Coefficients<float>::Ptr hpf,
                                                  juce::dsp::IIR::Coefficients<float>::Ptr lpf,
                                                  const bool isRightChannel)
{
    if (isRightChannel)
    {
        hpfR = hpf;
        lpfR = lpf;
    }
    else
    {
        hpfL = hpf;
        lpfL = lpf;
    }

    repaint();
}

float CrossoverGraphComponent::xForFreq (const float f) const
{
    return (std::log10 (f / 20.0f) / std::log10 (1000.0f)) * static_cast<float> (getWidth());
}

float CrossoverGraphComponent::freqForX (const float x) const
{
    return 20.0f * std::pow (10.0f, (x / static_cast<float> (getWidth())) * std::log10 (1000.0f));
}

float CrossoverGraphComponent::yForGain (const float dB) const
{
    return (1.0f - (dB + 24.0f) / 48.0f) * static_cast<float> (getHeight());
}

float CrossoverGraphComponent::gainForY (const float y) const
{
    return (1.0f - y / static_cast<float> (getHeight())) * 48.0f - 24.0f;
}

void CrossoverGraphComponent::drawCurve (juce::Graphics& g, const juce::Colour colour,
                                         juce::dsp::IIR::Coefficients<float>::Ptr coeffs) const
{
    if (coeffs == nullptr)
        return;

    juce::Path curve;

    for (int i = 0; i < 512; ++i)
    {
        const float t = static_cast<float> (i) / 511.0f;
        const float freq = freqForX (t * static_cast<float> (getWidth()));
        const float mag = coeffs->getMagnitudeForFrequency (freq, sampleRate);
        const float dB = juce::Decibels::gainToDecibels (mag, -48.0f);
        const auto x = t * static_cast<float> (getWidth());
        const auto y = yForGain (dB);

        if (i == 0)
            curve.startNewSubPath (x, y);
        else
            curve.lineTo (x, y);
    }

    g.setColour (colour);
    g.strokePath (curve, juce::PathStrokeType (2.0f));
}

void CrossoverGraphComponent::paint (juce::Graphics& g)
{
    g.fillAll (juce::Colour (0xFF0D0D0D));

    g.setColour (juce::Colour (0xFF2A2A2A));

    for (const float f : { 20.f, 50.f, 100.f, 200.f, 500.f, 1000.f, 2000.f, 5000.f, 10000.f, 20000.f })
        g.drawVerticalLine (static_cast<int> (xForFreq (f)), 0.0f, static_cast<float> (getHeight()));

    for (int db = -24; db <= 24; db += 6)
        g.drawHorizontalLine (static_cast<int> (yForGain (static_cast<float> (db))), 0.0f,
                              static_cast<float> (getWidth()));

    if (mode == Mode::InputDualChannel)
    {
        drawCurve (g, juce::Colour (0xFF2979FF), hpfL);
        drawCurve (g, juce::Colour (0xFF2979FF), lpfL);
        drawCurve (g, juce::Colour (0xFFFF6D00), hpfR);
        drawCurve (g, juce::Colour (0xFFFF6D00), lpfR);
    }
    else
    {
        drawCurve (g, juce::Colour (0xFFFF6D00), hpfR);
        drawCurve (g, juce::Colour (0xFFFF6D00), lpfR);
    }

    const auto nodeX = xForFreq (crossoverHz);
    const auto nodeY = yForGain (0.0f);
    g.setColour (juce::Colour (0xFF00E5FF));
    g.fillEllipse (nodeX - 6.0f, nodeY - 6.0f, 12.0f, 12.0f);
}

void CrossoverGraphComponent::mouseDown (const juce::MouseEvent& e)
{
    const auto node = juce::Point<float> (xForFreq (crossoverHz), yForGain (0.0f));
    dragging = node.getDistanceFrom (e.position) <= 10.0f;
}

void CrossoverGraphComponent::mouseDrag (const juce::MouseEvent& e)
{
    if (! dragging)
        return;

    crossoverHz = juce::jlimit (20.0f, 20000.0f, freqForX (e.position.x));
    setCrossoverFrequency (crossoverHz);
    listeners.call ([this] (Listener& l) { l.crossoverFreqChanged (crossoverHz); });
}

void CrossoverGraphComponent::mouseUp (const juce::MouseEvent&)
{
    dragging = false;
}
