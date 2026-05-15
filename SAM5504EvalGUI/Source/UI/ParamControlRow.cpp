#include "ParamControlRow.h"

ParamControlRow::ParamControlRow (ApplicationController& controller,
                                  const ParamId paramId,
                                  const juce::String& labelText)
    : appController (controller), param (paramId)
{
    nameLabel.setText (labelText, juce::dontSendNotification);
    nameLabel.setJustificationType (juce::Justification::centredLeft);
    nameLabel.setMinimumHorizontalScale (1.0f);
    nameLabel.setFont (juce::Font (juce::FontOptions ("IBM Plex Sans", 12.0f, juce::Font::plain)));

    valueLabel.setJustificationType (juce::Justification::centredRight);
    valueLabel.setMinimumHorizontalScale (1.0f);
    valueLabel.setFont (juce::Font (juce::FontOptions ("IBM Plex Mono", 12.0f, juce::Font::plain)));

    slider.setRange (0.0, 1.0, 0.001);
    slider.setSliderStyle (juce::Slider::LinearHorizontal);
    slider.setTextBoxStyle (juce::Slider::NoTextBox, false, 0, 0);
    slider.onValueChange = [this]
    {
        const auto v = static_cast<float> (slider.getValue());
        appController.setParameter (param, v);
        valueLabel.setText (juce::String (v, 3), juce::dontSendNotification);
    };

    addAndMakeVisible (nameLabel);
    addAndMakeVisible (slider);
    addAndMakeVisible (valueLabel);
    syncFromState();
}

void ParamControlRow::resized()
{
    FlexBoxLayout::layoutParamRow (getLocalBounds(), nameLabel, slider, valueLabel);
}

void ParamControlRow::syncFromState()
{
    const auto v = appController.getState().getNormalised (param);
    slider.setValue (v, juce::dontSendNotification);
    valueLabel.setText (juce::String (v, 3), juce::dontSendNotification);
}
