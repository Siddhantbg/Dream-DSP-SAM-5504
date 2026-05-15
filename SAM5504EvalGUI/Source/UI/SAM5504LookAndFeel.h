#pragma once

#include <JuceHeader.h>

class SAM5504LookAndFeel : public juce::LookAndFeel_V4
{
public:
    SAM5504LookAndFeel();

    juce::Font getTextButtonFont (juce::TextButton&, int buttonHeight) override;
    juce::Font getLabelFont (juce::Label&) override;

    void drawLinearSlider (juce::Graphics&, int x, int y, int width, int height,
                           float sliderPos, float minSliderPos, float maxSliderPos,
                           const juce::Slider::SliderStyle, juce::Slider&) override;

    void drawRotarySlider (juce::Graphics&, int x, int y, int width, int height,
                           float sliderPosProportional, float rotaryStartAngle,
                           float rotaryEndAngle, juce::Slider&) override;

    void drawButtonBackground (juce::Graphics&, juce::Button&, const juce::Colour& backgroundColour,
                               bool shouldDrawButtonAsHighlighted,
                               bool shouldDrawButtonAsDown) override;

    void drawTabButton (juce::TabBarButton&, juce::Graphics&, bool isMouseOver, bool isMouseDown) override;

    void drawGroupComponentOutline (juce::Graphics&, int width, int height,
                                    const juce::String& text,
                                    const juce::Justification&,
                                    juce::GroupComponent&) override;

private:
    juce::Font sansFont;
    juce::Font monoFont;
};
