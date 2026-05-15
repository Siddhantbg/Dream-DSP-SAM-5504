#pragma once

#include "ApplicationController.h"
#include "UI/SAM5504LookAndFeel.h"
#include "UI/sections/InputSection.h"
#include "UI/sections/MidSectionPanel.h"
#include "UI/sections/SubSectionPanel.h"
#include <JuceHeader.h>

class MainComponent : public juce::Component,
                      private juce::ComboBox::Listener,
                      private juce::Button::Listener
{
public:
    explicit MainComponent (ApplicationController& controller);
    ~MainComponent() override;

    void paint (juce::Graphics& g) override;
    void resized() override;

private:
    void comboBoxChanged (juce::ComboBox* box) override;
    void buttonClicked (juce::Button* button) override;
    void refreshMidiDeviceLists();
    int findPreferredMidiIndex (const juce::StringArray& names) const;

    ApplicationController& app;
    SAM5504LookAndFeel lookAndFeel;

    juce::Label titleLabel;
    juce::ComboBox midiInputBox, midiOutputBox;
    juce::TextButton connectButton { "Connect MIDI" };
    juce::Label statusLabel;

    InputSection inputSection;

    SubSectionPanel lSubPanel, rSubPanel;
    MidSectionPanel lMidPanel, rMidPanel;

    juce::TabbedComponent tabs { juce::TabbedButtonBar::TabsAtTop };
    juce::Viewport lSubViewport, lMidViewport, rSubViewport, rMidViewport;
};
