#pragma once

#include <JuceHeader.h>

namespace FlexBoxLayout
{
inline void layoutParamRow (juce::Rectangle<int> area,
                            juce::Component& label,
                            juce::Component& control,
                            juce::Component& valueLabel)
{
    juce::FlexBox row;
    row.flexDirection = juce::FlexBox::Direction::row;
    row.alignItems = juce::FlexBox::AlignItems::center;
    row.items.add (juce::FlexItem (label).withWidth (120.0f).withHeight (24.0f));
    row.items.add (juce::FlexItem (control).withFlex (1.0f).withHeight (24.0f));
    row.items.add (juce::FlexItem (valueLabel).withWidth (60.0f).withHeight (24.0f));
    row.performLayout (area.reduced (8, 0).toFloat());
}
} // namespace FlexBoxLayout
