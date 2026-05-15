#include "InputSection.h"

InputSection::InputSection (ApplicationController& controller)
    : app (controller),
      leftGain (controller, ParamId::Input_LeftGain, "Left Gain"),
      rightGain (controller, ParamId::Input_RightGain, "Right Gain")
{
    heading.setText ("Input", juce::dontSendNotification);
    heading.setFont (juce::Font (juce::FontOptions ("IBM Plex Sans", 14.0f, juce::Font::bold)));
    heading.setJustificationType (juce::Justification::centredLeft);
    heading.setMinimumHorizontalScale (1.0f);

    crossoverGraph.setMode (CrossoverGraphComponent::Mode::InputDualChannel);
    eqGraph.addListener (this);
    crossoverGraph.addListener (this);

    leftMute.onClick = [this] { app.setMute (true, ! app.getState().inputLeftMuted); };
    rightMute.onClick = [this] { app.setMute (false, ! app.getState().inputRightMuted); };

    addAndMakeVisible (heading);
    addAndMakeVisible (leftMute);
    addAndMakeVisible (rightMute);
    addAndMakeVisible (leftGain);
    addAndMakeVisible (rightGain);
    addAndMakeVisible (eqGraph);
    addAndMakeVisible (crossoverGraph);
}

void InputSection::resized()
{
    auto area = getLocalBounds().reduced (8);
    heading.setBounds (area.removeFromTop (24));
    area.removeFromTop (16);

    auto muteRow = area.removeFromTop (rowHeight);
    leftMute.setBounds (muteRow.removeFromLeft (100));
    muteRow.removeFromLeft (8);
    rightMute.setBounds (muteRow.removeFromLeft (100));

    area.removeFromTop (8);
    leftGain.setBounds (area.removeFromTop (rowHeight));
    area.removeFromTop (8);
    rightGain.setBounds (area.removeFromTop (rowHeight));
    area.removeFromTop (16);

    auto graphs = area.removeFromTop (juce::jmin (220, area.getHeight() / 2));
    eqGraph.setBounds (graphs.removeFromTop (graphs.getHeight() / 2).reduced (0, 4));
    crossoverGraph.setBounds (graphs.reduced (0, 4));
}

void InputSection::eqBandChanged (int, float, float, float) {}
void InputSection::crossoverFreqChanged (float newFreqHz)
{
    app.getState().inputCrossoverFreq = newFreqHz;
    crossoverGraph.setCrossoverFrequency (newFreqHz);
}
