#pragma once

#include <JuceHeader.h>
#include <array>

class EQGraphComponent : public juce::Component
{
public:
    struct Listener
    {
        virtual ~Listener() = default;
        virtual void eqBandChanged (int band, float freqHz, float gainDB, float Q) = 0;
    };

    EQGraphComponent();

    void setSampleRate (double sr) { sampleRate = sr; repaint(); }
    void setBandParameters (int band, float freqHz, float gainDB, float Q);
    void setFilterCoefficients (int band, juce::dsp::IIR::Coefficients<float>::Ptr coeffs);

    void addListener (Listener* l) { listeners.add (l); }
    void removeListener (Listener* l) { listeners.remove (l); }

    void paint (juce::Graphics& g) override;
    void mouseDown (const juce::MouseEvent& e) override;
    void mouseDrag (const juce::MouseEvent& e) override;
    void mouseUp (const juce::MouseEvent&) override;

private:
    float xForFreq (float f) const;
    float freqForX (float x) const;
    float yForGain (float dB) const;
    float gainForY (float y) const;
    int findClosestNode (juce::Point<float> p) const;

    struct BandState
    {
        float freqHz = 1000.0f;
        float gainDB = 0.0f;
        float Q = 0.707f;
        juce::dsp::IIR::Coefficients<float>::Ptr coeffs;
    };

    std::array<BandState, 3> bands;
    double sampleRate = 48000.0;
    int activeNode = -1;
    juce::ListenerList<Listener> listeners;
};
