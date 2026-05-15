#include "EQGraphComponent.h"

EQGraphComponent::EQGraphComponent()
{
    bands[0].freqHz = 100.0f;
    bands[1].freqHz = 1000.0f;
    bands[2].freqHz = 8000.0f;

    for (auto& b : bands)
        b.coeffs = juce::dsp::IIR::Coefficients<float>::makePeakFilter (sampleRate, b.freqHz, b.Q, 1.0f);
}

void EQGraphComponent::setBandParameters (const int band, const float freqHz, const float gainDB, const float Q)
{
    if (band < 0 || band >= 3)
        return;

    bands[static_cast<size_t> (band)] = { freqHz, gainDB, Q, bands[static_cast<size_t> (band)].coeffs };
    repaint();
}

void EQGraphComponent::setFilterCoefficients (const int band,
                                              juce::dsp::IIR::Coefficients<float>::Ptr coeffs)
{
    if (band < 0 || band >= 3)
        return;

    bands[static_cast<size_t> (band)].coeffs = coeffs;
    repaint();
}

float EQGraphComponent::xForFreq (const float f) const
{
    return (std::log10 (f / 20.0f) / std::log10 (1000.0f)) * static_cast<float> (getWidth());
}

float EQGraphComponent::freqForX (const float x) const
{
    return 20.0f * std::pow (10.0f, (x / static_cast<float> (getWidth())) * std::log10 (1000.0f));
}

float EQGraphComponent::yForGain (const float dB) const
{
    return (1.0f - (dB + 24.0f) / 48.0f) * static_cast<float> (getHeight());
}

float EQGraphComponent::gainForY (const float y) const
{
    return (1.0f - y / static_cast<float> (getHeight())) * 48.0f - 24.0f;
}

int EQGraphComponent::findClosestNode (const juce::Point<float> p) const
{
    int best = -1;
    float bestDist = 100.0f;

    for (int i = 0; i < 3; ++i)
    {
        const auto pt = juce::Point<float> (xForFreq (bands[static_cast<size_t> (i)].freqHz),
                                            yForGain (bands[static_cast<size_t> (i)].gainDB));
        const float d = pt.getDistanceFrom (p);

        if (d < bestDist)
        {
            bestDist = d;
            best = i;
        }
    }

    return bestDist <= 10.0f ? best : -1;
}

void EQGraphComponent::paint (juce::Graphics& g)
{
    g.fillAll (juce::Colour (0xFF0D0D0D));

    const float gridFreqs[] = { 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000, 20000 };

    g.setColour (juce::Colour (0xFF2A2A2A));

    for (const auto f : gridFreqs)
    {
        const auto x = xForFreq (f);
        g.drawVerticalLine (static_cast<int> (x), 0.0f, static_cast<float> (getHeight()));
    }

    for (int db = -24; db <= 24; db += 6)
    {
        const auto y = yForGain (static_cast<float> (db));
        g.drawHorizontalLine (static_cast<int> (y), 0.0f, static_cast<float> (getWidth()));
    }

    juce::Path curve;

    for (int i = 0; i < 512; ++i)
    {
        const float t = static_cast<float> (i) / 511.0f;
        const float freq = freqForX (t * static_cast<float> (getWidth()));
        double mag = 1.0;

        for (const auto& b : bands)
        {
            if (b.coeffs != nullptr)
                mag *= b.coeffs->getMagnitudeForFrequency (freq, sampleRate);
        }

        const float dB = juce::Decibels::gainToDecibels (static_cast<float> (mag), -48.0f);
        const auto x = t * static_cast<float> (getWidth());
        const auto y = yForGain (dB);

        if (i == 0)
            curve.startNewSubPath (x, y);
        else
            curve.lineTo (x, y);
    }

    g.setColour (juce::Colour (0xFF00E5FF));
    g.strokePath (curve, juce::PathStrokeType (2.0f));

    for (const auto& b : bands)
    {
        g.setColour (juce::Colour (0xFF00E5FF));
        g.fillEllipse (xForFreq (b.freqHz) - 6.0f, yForGain (b.gainDB) - 6.0f, 12.0f, 12.0f);
    }
}

void EQGraphComponent::mouseDown (const juce::MouseEvent& e)
{
    activeNode = findClosestNode (e.position);
}

void EQGraphComponent::mouseDrag (const juce::MouseEvent& e)
{
    if (activeNode < 0)
        return;

    auto& b = bands[static_cast<size_t> (activeNode)];
    b.freqHz = juce::jlimit (20.0f, 20000.0f, freqForX (e.position.x));
    b.gainDB = juce::jlimit (-24.0f, 24.0f, gainForY (e.position.y));
    listeners.call ([this] (Listener& l) { l.eqBandChanged (activeNode, bands[static_cast<size_t> (activeNode)].freqHz,
                                                             bands[static_cast<size_t> (activeNode)].gainDB,
                                                             bands[static_cast<size_t> (activeNode)].Q); });
    repaint();
}

void EQGraphComponent::mouseUp (const juce::MouseEvent&)
{
    activeNode = -1;
}
