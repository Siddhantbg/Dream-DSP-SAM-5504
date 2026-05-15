#include "MainComponent.h"

MainComponent::MainComponent (ApplicationController& controller)
    : app (controller),
      inputSection (controller),
      lSubPanel (controller, "L Sub",
                 ParamId::LSub_OutputGain, ParamId::LSub_CompThreshold,
                 ParamId::LSub_CompAttack, ParamId::LSub_CompRelease,
                 ParamId::LSub_CompMakeup, true),
      rSubPanel (controller, "R Sub",
                 ParamId::RSub_OutputGain, ParamId::RSub_CompThreshold,
                 ParamId::RSub_CompAttack, ParamId::RSub_CompRelease,
                 ParamId::RSub_CompMakeup, false),
      lMidPanel (controller, "L Mid",
                 ParamId::LMid_DelayTime, ParamId::LMid_DelayGain,
                 ParamId::LMid_OutputGain, false),
      rMidPanel (controller, "R Mid",
                 ParamId::RMid_DelayTime, ParamId::RMid_DelayGain,
                 ParamId::RMid_OutputGain, true)
{
    setLookAndFeel (&lookAndFeel);

    titleLabel.setText ("SAM5504 Eval Board", juce::dontSendNotification);
    titleLabel.setFont (juce::Font (juce::FontOptions ("IBM Plex Mono", 14.0f, juce::Font::bold)));
    titleLabel.setJustificationType (juce::Justification::centredRight);
    titleLabel.setMinimumHorizontalScale (1.0f);

    statusLabel.setJustificationType (juce::Justification::centredLeft);
    statusLabel.setMinimumHorizontalScale (1.0f);

    midiInputBox.addListener (this);
    midiOutputBox.addListener (this);
    connectButton.addListener (this);

    for (auto* vp : { &lSubViewport, &lMidViewport, &rSubViewport, &rMidViewport })
    {
        vp->setScrollBarsShown (true, false);
        vp->setScrollBarThickness (10);
    }

    lSubViewport.setViewedComponent (&lSubPanel, false);
    lMidViewport.setViewedComponent (&lMidPanel, false);
    rSubViewport.setViewedComponent (&rSubPanel, false);
    rMidViewport.setViewedComponent (&rMidPanel, false);

    tabs.addTab ("L Sub", juce::Colour (0xFF0A0A0A), &lSubViewport, false);
    tabs.addTab ("L Mid", juce::Colour (0xFF0A0A0A), &lMidViewport, false);
    tabs.addTab ("R Sub", juce::Colour (0xFF0A0A0A), &rSubViewport, false);
    tabs.addTab ("R Mid", juce::Colour (0xFF0A0A0A), &rMidViewport, false);

    addAndMakeVisible (titleLabel);
    addAndMakeVisible (midiInputBox);
    addAndMakeVisible (midiOutputBox);
    addAndMakeVisible (connectButton);
    addAndMakeVisible (statusLabel);
    addAndMakeVisible (inputSection);
    addAndMakeVisible (tabs);

    refreshMidiDeviceLists();

    app.onStateChanged = [this]
    {
        statusLabel.setText (app.getFirmwareComms().isConnected() ? "MIDI: Connected"
                                                                  : "MIDI: Disconnected",
                             juce::dontSendNotification);
    };

    setSize (1100, 800);
}

MainComponent::~MainComponent()
{
    setLookAndFeel (nullptr);
}

void MainComponent::paint (juce::Graphics& g)
{
    g.fillAll (juce::Colour (0xFF0A0A0A));
}

void MainComponent::resized()
{
    auto bounds = getLocalBounds().reduced (8);
    titleLabel.setBounds (bounds.getWidth() - 220, 8, 210, 24);
    titleLabel.toFront (false);

    auto midiRow = bounds.removeFromTop (28);
    midiInputBox.setBounds (midiRow.removeFromLeft (220));
    midiRow.removeFromLeft (8);
    midiOutputBox.setBounds (midiRow.removeFromLeft (220));
    midiRow.removeFromLeft (8);
    connectButton.setBounds (midiRow.removeFromLeft (120));
    midiRow.removeFromLeft (8);
    statusLabel.setBounds (midiRow);

    bounds.removeFromTop (8);
    inputSection.setBounds (bounds.removeFromTop (280));
    bounds.removeFromTop (8);
    tabs.setBounds (bounds);

    const auto tabContent = tabs.getLocalBounds().reduced (4);
    const int contentH = 900;

    lSubPanel.setSize (tabContent.getWidth(), contentH);
    lMidPanel.setSize (tabContent.getWidth(), contentH);
    rSubPanel.setSize (tabContent.getWidth(), contentH);
    rMidPanel.setSize (tabContent.getWidth(), contentH);

    lSubViewport.setViewedComponent (&lSubPanel, false);
    lMidViewport.setViewedComponent (&lMidPanel, false);
    rSubViewport.setViewedComponent (&rSubPanel, false);
    rMidViewport.setViewedComponent (&rMidPanel, false);
}

void MainComponent::comboBoxChanged (juce::ComboBox*) {}
void MainComponent::buttonClicked (juce::Button* b)
{
    if (b != &connectButton)
        return;

    if (app.getFirmwareComms().isConnected())
    {
        app.disconnectMidi();
    }
    else
    {
        const auto inName = midiInputBox.getText();
        const auto outName = midiOutputBox.getText();
        app.connectMidi (inName, outName);
    }

    statusLabel.setText (app.getFirmwareComms().isConnected() ? "MIDI: Connected" : "MIDI: Disconnected",
                         juce::dontSendNotification);
}

void MainComponent::refreshMidiDeviceLists()
{
    midiInputBox.clear();
    midiOutputBox.clear();

    const auto inputs = app.getFirmwareComms().getMidiInputNames();
    const auto outputs = app.getFirmwareComms().getMidiOutputNames();

    for (int i = 0; i < inputs.size(); ++i)
        midiInputBox.addItem (inputs[i], i + 1);

    for (int i = 0; i < outputs.size(); ++i)
        midiOutputBox.addItem (outputs[i], i + 1);

    if (inputs.size() > 0)
        midiInputBox.setSelectedItemIndex (findPreferredMidiIndex (inputs), juce::dontSendNotification);

    if (outputs.size() > 0)
        midiOutputBox.setSelectedItemIndex (findPreferredMidiIndex (outputs), juce::dontSendNotification);
}

int MainComponent::findPreferredMidiIndex (const juce::StringArray& names) const
{
    for (int i = 0; i < names.size(); ++i)
    {
        const auto n = names[i].toLowerCase();

        if (n.contains ("dream") || n.contains ("5504") || n.contains ("sam"))
            return i;
    }

    return 0;
}
