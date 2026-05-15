#include "SubSectionPanel.h"

SubSectionPanel::SubSectionPanel (ApplicationController& controller,
                                  const juce::String& title,
                                  const ParamId outputGainId,
                                  const ParamId thresholdId,
                                  const ParamId attackId,
                                  const ParamId releaseId,
                                  const ParamId makeupId,
                                  const bool isLeftLimiter)
    : app (controller),
      outputGain (controller, outputGainId, "Output Gain"),
      threshold (controller, thresholdId, "Threshold"),
      attack (controller, attackId, "Attack"),
      release (controller, releaseId, "Release"),
      makeup (controller, makeupId, "Makeup"),
      leftLimiter (isLeftLimiter)
{
    heading.setText (title, juce::dontSendNotification);
    heading.setFont (juce::Font (juce::FontOptions ("IBM Plex Sans", 14.0f, juce::Font::bold)));
    heading.setJustificationType (juce::Justification::centredLeft);
    heading.setMinimumHorizontalScale (1.0f);

    grLabel.setJustificationType (juce::Justification::centredRight);
    grLabel.setFont (juce::Font (juce::FontOptions ("IBM Plex Mono", 12.0f, juce::Font::plain)));
    grLabel.setMinimumHorizontalScale (1.0f);

    eqGraph.addListener (this);

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

    if (leftLimiter)
        app.setParameter (ParamId::LSub_CompRatio, 1.0f);

    addAndMakeVisible (heading);
    addAndMakeVisible (grLabel);
    addAndMakeVisible (muteButton);
    addAndMakeVisible (outputGain);
    addAndMakeVisible (threshold);
    addAndMakeVisible (attack);
    addAndMakeVisible (release);
    addAndMakeVisible (makeup);
    addAndMakeVisible (eqGraph);
    startTimerHz (30);
}

void SubSectionPanel::resized()
{
    auto area = getLocalBounds().reduced (8);
    auto top = area.removeFromTop (24);
    heading.setBounds (top.removeFromLeft (top.getWidth() / 2));
    grLabel.setBounds (top);

    area.removeFromTop (16);
    auto muteRow = area.removeFromTop (rowHeight);
    muteButton.setBounds (muteRow.removeFromLeft (80));
    muteRow.removeFromLeft (8);
    outputGain.setBounds (muteRow);

    area.removeFromTop (8);
    threshold.setBounds (area.removeFromTop (rowHeight));
    area.removeFromTop (8);
    attack.setBounds (area.removeFromTop (rowHeight));
    area.removeFromTop (8);
    release.setBounds (area.removeFromTop (rowHeight));
    area.removeFromTop (8);
    makeup.setBounds (area.removeFromTop (rowHeight));
    area.removeFromTop (16);
    eqGraph.setBounds (area.removeFromTop (juce::jmin (180, area.getHeight())));
}

void SubSectionPanel::timerCallback()
{
    const auto& ch = app.getState().channelForParam (threshold.getParamId());
    grLabel.setText ("GR: " + juce::String (ch.gainReductionDb, 1) + " dB",
                     juce::dontSendNotification);
    app.getFirmwareComms().pollGainReduction();
}

void SubSectionPanel::eqBandChanged (const int band, const float freqHz, const float gainDB, const float Q)
{
    auto& ch = app.getState().channelForParam (outputGain.getParamId());
    ch.eqBands[static_cast<size_t> (band)] = { freqHz, gainDB, Q, "Peak" };
    eqGraph.setBandParameters (band, freqHz, gainDB, Q);
    eqGraph.repaint();
}
