#pragma once

#include "../ApplicationController.h"
#include "FlexBoxLayout.h"
#include <functional>
#include <JuceHeader.h>

class ParamControlRow : public juce::Component
{
public:
    ParamControlRow (ApplicationController& controller,
                     ParamId paramId,
                     const juce::String& labelText);

    void resized() override;
    void syncFromState();

    juce::Slider& getSlider() { return slider; }
    ParamId getParamId() const { return param; }

private:
    ApplicationController& appController;
    ParamId param;
    juce::Label nameLabel;
    juce::Slider slider;
    juce::Label valueLabel;
};
