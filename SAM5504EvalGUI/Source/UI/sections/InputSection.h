#pragma once

#include "../../ApplicationController.h"
#include "../graphs/CrossoverGraphComponent.h"
#include "../graphs/EQGraphComponent.h"
#include "../ParamControlRow.h"
#include <JuceHeader.h>

class InputSection : public juce::Component,
                     public EQGraphComponent::Listener,
                     public CrossoverGraphComponent::Listener
{
public:
    explicit InputSection (ApplicationController& controller);

    void resized() override;
    void eqBandChanged (int band, float freqHz, float gainDB, float Q) override;
    void crossoverFreqChanged (float newFreqHz) override;

private:
    ApplicationController& app;
    juce::Label heading;
    juce::TextButton leftMute { "L Mute" }, rightMute { "R Mute" };
    ParamControlRow leftGain, rightGain;
    EQGraphComponent eqGraph;
    CrossoverGraphComponent crossoverGraph;
    int rowHeight = 32;
};
