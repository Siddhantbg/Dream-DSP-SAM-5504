#pragma once

#include "../../ApplicationController.h"
#include "../graphs/CrossoverGraphComponent.h"
#include "../graphs/EQGraphComponent.h"
#include "../ParamControlRow.h"
#include <JuceHeader.h>

class MidSectionPanel : public juce::Component,
                        public EQGraphComponent::Listener,
                        public CrossoverGraphComponent::Listener
{
public:
    MidSectionPanel (ApplicationController& controller,
                     const juce::String& title,
                     ParamId delayTimeId,
                     ParamId delayGainId,
                     ParamId outputGainId,
                     bool showCrossover);

    void resized() override;
    void eqBandChanged (int band, float freqHz, float gainDB, float Q) override;
    void crossoverFreqChanged (float newFreqHz) override;

private:
    ApplicationController& app;
    juce::Label heading;
    juce::TextButton muteButton { "Mute" }, phaseButton { "Phase" };
    ParamControlRow delayTime, delayGain, outputGain;
    EQGraphComponent eqGraph;
    CrossoverGraphComponent crossoverGraph;
    bool withCrossover;
    int rowHeight = 32;
};
