#include "SAM5504LookAndFeel.h"

SAM5504LookAndFeel::SAM5504LookAndFeel()
{
    setColour (juce::ResizableWindow::backgroundColourId, juce::Colour (0xFF0A0A0A));
    setColour (juce::DocumentWindow::backgroundColourId, juce::Colour (0xFF0A0A0A));
    setColour (juce::Slider::backgroundColourId, juce::Colour (0xFF2A2A2A));
    setColour (juce::Slider::trackColourId, juce::Colour (0xFF00E5FF));
    setColour (juce::Slider::thumbColourId, juce::Colour (0xFF00E5FF));
    setColour (juce::Label::textColourId, juce::Colour (0xFFE0E0E0));
    setColour (juce::TextButton::buttonColourId, juce::Colour (0xFF1A1A1A));
    setColour (juce::TextButton::buttonOnColourId, juce::Colour (0xFF003344));
    setColour (juce::TextButton::textColourOffId, juce::Colour (0xFF888888));
    setColour (juce::TextButton::textColourOnId, juce::Colour (0xFF00E5FF));
    setColour (juce::ComboBox::backgroundColourId, juce::Colour (0xFF1A1A1A));
    setColour (juce::ComboBox::textColourId, juce::Colour (0xFFE0E0E0));
    setColour (juce::TabbedComponent::backgroundColourId, juce::Colour (0xFF0A0A0A));

    sansFont = juce::Font (juce::FontOptions ("IBM Plex Sans", 12.0f, juce::Font::plain));
    monoFont = juce::Font (juce::FontOptions ("IBM Plex Mono", 12.0f, juce::Font::plain));
}

juce::Font SAM5504LookAndFeel::getTextButtonFont (juce::TextButton&, const int buttonHeight)
{
    return sansFont.withHeight (static_cast<float> (buttonHeight) * 0.55f);
}

juce::Font SAM5504LookAndFeel::getLabelFont (juce::Label& label)
{
    return label.getFont().getTypefaceName().containsIgnoreCase ("Mono") ? monoFont : sansFont;
}

void SAM5504LookAndFeel::drawLinearSlider (juce::Graphics& g, int x, int y, int width, int height,
                                           float sliderPos, float, float,
                                           const juce::Slider::SliderStyle style, juce::Slider& slider)
{
    if (style != juce::Slider::LinearHorizontal && style != juce::Slider::LinearVertical)
    {
        LookAndFeel_V4::drawLinearSlider (g, x, y, width, height, sliderPos,
                                          0, 0, style, slider);
        return;
    }

    const auto track = juce::Rectangle<float> (static_cast<float> (x),
                                               static_cast<float> (y + height / 2 - 2),
                                               static_cast<float> (width),
                                               4.0f);
    g.setColour (juce::Colour (0xFF2A2A2A));
    g.fillRoundedRectangle (track, 2.0f);

    auto fill = track;
    fill.setWidth (sliderPos - static_cast<float> (x));
    g.setColour (juce::Colour (0xFF00E5FF));
    g.fillRoundedRectangle (fill, 2.0f);

    g.setColour (juce::Colour (0xFF00E5FF));
    g.fillEllipse (sliderPos - 6.0f, static_cast<float> (y + height / 2 - 6), 12.0f, 12.0f);
}

void SAM5504LookAndFeel::drawRotarySlider (juce::Graphics& g, int x, int y, int width, int height,
                                           float sliderPos, float startAngle, float endAngle,
                                           juce::Slider& slider)
{
    const auto bounds = juce::Rectangle<float> (static_cast<float> (x), static_cast<float> (y),
                                                static_cast<float> (width), static_cast<float> (height))
                            .reduced (4.0f);
    const auto radius = juce::jmin (bounds.getWidth(), bounds.getHeight()) / 2.0f;
    const auto centre = bounds.getCentre();
    const auto angle = startAngle + sliderPos * (endAngle - startAngle);

    g.setColour (juce::Colour (0xFF2A2A2A));
    g.fillEllipse (bounds);

    juce::Path arc;
    arc.addCentredArc (centre.x, centre.y, radius, radius, 0.0f, startAngle, angle, true);
    g.setColour (juce::Colour (0xFF00E5FF));
    g.strokePath (arc, juce::PathStrokeType (3.0f));

    juce::ignoreUnused (slider);
}

void SAM5504LookAndFeel::drawButtonBackground (juce::Graphics& g, juce::Button& button,
                                               const juce::Colour&, bool, bool)
{
    const auto bounds = button.getLocalBounds().toFloat().reduced (1.0f);
    const auto active = button.getToggleState();
    g.setColour (active ? juce::Colour (0xFF003344) : juce::Colour (0xFF1A1A1A));
    g.fillRoundedRectangle (bounds, 4.0f);
    g.setColour (active ? juce::Colour (0xFF00E5FF) : juce::Colour (0xFF2A2A2A));
    g.drawRoundedRectangle (bounds, 4.0f, 1.0f);
}

void SAM5504LookAndFeel::drawTabButton (juce::TabBarButton& button, juce::Graphics& g,
                                        bool isMouseOver, bool isMouseDown)
{
    const auto active = button.isFrontTab();
    auto area = button.getLocalBounds();
    g.setColour (juce::Colour (0xFF0A0A0A));
    g.fillRect (area);

    if (active)
    {
        g.setColour (juce::Colour (0xFF00E5FF));
        g.fillRect (area.removeFromBottom (3));
    }

    g.setColour (active ? juce::Colour (0xFF00E5FF)
                        : (isMouseOver || isMouseDown ? juce::Colour (0xFFBBBBBB)
                                                      : juce::Colour (0xFF888888)));
    g.setFont (sansFont);
    g.drawText (button.getButtonText(), button.getLocalBounds(), juce::Justification::centred);
}

void SAM5504LookAndFeel::drawGroupComponentOutline (juce::Graphics& g, int width, int height,
                                                    const juce::String& text,
                                                    const juce::Justification&,
                                                    juce::GroupComponent& group)
{
    const auto bounds = juce::Rectangle<float> (0.0f, 0.0f, static_cast<float> (width),
                                                static_cast<float> (height));
    g.setColour (juce::Colour (0xFF2A2A2A));
    g.drawRoundedRectangle (bounds.reduced (0.5f), 4.0f, 1.0f);
    g.setFont (sansFont);
    g.setColour (juce::Colour (0xFFE0E0E0));
    g.drawText (text, 10, 0, width - 20, 18, juce::Justification::centredLeft);
    juce::ignoreUnused (group);
}
