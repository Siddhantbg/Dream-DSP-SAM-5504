#pragma once

#include "EQGraphComponent.h"
#include <optional>

class CrossoverGraphComponent : public juce::Component
{
public:
    enum class Mode { InputDualChannel, RMidSingle };

    struct Listener
    {
        virtual ~Listener() = default;
        virtual void crossoverFreqChanged (float newFreqHz) = 0;
    };

    CrossoverGraphComponent();

    void setMode (Mode m) { mode = m; repaint(); }
    void setSampleRate (double sr) { sampleRate = sr; repaint(); }
    void setCrossoverFrequency (float hz);
    void setHPFCoefficients (juce::dsp::IIR::Coefficients<float>::Ptr hpf,
                             juce::dsp::IIR::Coefficients<float>::Ptr lpf,
                             bool isRightChannel);

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
    void drawCurve (juce::Graphics& g, juce::Colour colour,
                    juce::dsp::IIR::Coefficients<float>::Ptr coeffs) const;

    Mode mode = Mode::InputDualChannel;
    float crossoverHz = 1000.0f;
    double sampleRate = 48000.0;
    bool dragging = false;

    juce::dsp::IIR::Coefficients<float>::Ptr hpfL, lpfL, hpfR, lpfR;
    juce::ListenerList<Listener> listeners;
};
