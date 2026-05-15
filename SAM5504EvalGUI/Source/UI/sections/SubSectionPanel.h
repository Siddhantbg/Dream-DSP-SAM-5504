#pragma once

#include "../../ApplicationController.h"
#include "../graphs/EQGraphComponent.h"
#include "../ParamControlRow.h"
#include <JuceHeader.h>

class SubSectionPanel : public juce::Component,
                        public juce::Timer,
                        public EQGraphComponent::Listener
{
public:
    SubSectionPanel (ApplicationController& controller,
                     const juce::String& title,
                     ParamId outputGainId,
                     ParamId thresholdId,
                     ParamId attackId,
                     ParamId releaseId,
                     ParamId makeupId,
                     bool isLeftLimiter);

    void resized() override;
    void timerCallback() override;
    void eqBandChanged (int band, float freqHz, float gainDB, float Q) override;

private:
    ApplicationController& app;
    juce::Label heading, grLabel;
    juce::TextButton muteButton { "Mute" };
    ParamControlRow outputGain, threshold, attack, release, makeup;
    EQGraphComponent eqGraph;
    int rowHeight = 32;
    bool leftLimiter;
};
