#include "MidSectionPanel.h"

MidSectionPanel::MidSectionPanel (ApplicationController& controller,
                                  const juce::String& title,
                                  const ParamId delayTimeId,
                                  const ParamId delayGainId,
                                  const ParamId outputGainId,
                                  const bool showCrossover)
    : app (controller),
      delayTime (controller, delayTimeId, "Delay Time"),
      delayGain (controller, delayGainId, "Delay Gain"),
      outputGain (controller, outputGainId, "Output Gain"),
      withCrossover (showCrossover)
{
    heading.setText (title, juce::dontSendNotification);
    heading.setFont (juce::Font (juce::FontOptions ("IBM Plex Sans", 14.0f, juce::Font::bold)));
    heading.setJustificationType (juce::Justification::centredLeft);
    heading.setMinimumHorizontalScale (1.0f);

    eqGraph.addListener (this);
    crossoverGraph.addListener (this);

    if (showCrossover)
        crossoverGraph.setMode (CrossoverGraphComponent::Mode::RMidSingle);

    muteButton.onClick = [this, outputGainId]
    {
        auto& st = app.getState().channelForParam (outputGainId);
        st.muted = ! st.muted;

        if (st.muted)
        {
            st.prevGain = st.outputGain;
            app.setParameter (outputGainId, 0.0f);
        }
        else
        {
            app.setParameter (outputGainId, st.prevGain);
        }
    };

    phaseButton.onClick = [this, outputGainId]
    {
        auto& st = app.getState().channelForParam (outputGainId);
        st.phaseInverted = ! st.phaseInverted;
        phaseButton.setToggleState (st.phaseInverted, juce::dontSendNotification);
    };

    addAndMakeVisible (heading);
    addAndMakeVisible (muteButton);
    addAndMakeVisible (phaseButton);
    addAndMakeVisible (delayTime);
    addAndMakeVisible (delayGain);
    addAndMakeVisible (outputGain);
    addAndMakeVisible (eqGraph);

    if (withCrossover)
        addAndMakeVisible (crossoverGraph);
}

void MidSectionPanel::resized()
{
    auto area = getLocalBounds().reduced (8);
    heading.setBounds (area.removeFromTop (24));
    area.removeFromTop (16);

    auto muteRow = area.removeFromTop (rowHeight);
    muteButton.setBounds (muteRow.removeFromLeft (80));
    muteRow.removeFromLeft (8);
    phaseButton.setBounds (muteRow.removeFromLeft (80));
    muteRow.removeFromLeft (8);
    outputGain.setBounds (muteRow);

    area.removeFromTop (8);
    delayTime.setBounds (area.removeFromTop (rowHeight));
    area.removeFromTop (8);
    delayGain.setBounds (area.removeFromTop (rowHeight));
    area.removeFromTop (16);

    if (withCrossover)
    {
        auto graphs = area.removeFromTop (juce::jmin (220, area.getHeight()));
        eqGraph.setBounds (graphs.removeFromTop (graphs.getHeight() / 2).reduced (0, 4));
        crossoverGraph.setBounds (graphs.reduced (0, 4));
    }
    else
    {
        eqGraph.setBounds (area.removeFromTop (juce::jmin (180, area.getHeight())));
    }
}

void MidSectionPanel::eqBandChanged (int, float, float, float) { eqGraph.repaint(); }

void MidSectionPanel::crossoverFreqChanged (const float newFreqHz)
{
    app.getState().channelForParam (delayTime.getParamId()).crossoverFreq = newFreqHz;
    crossoverGraph.setCrossoverFrequency (newFreqHz);
}
