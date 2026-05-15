#pragma once

#include "../AppState.h"
#include <functional>
#include <JuceHeader.h>

class FirmwareComms : private juce::MidiInputCallback
{
public:
    using GainReductionCallback = std::function<void (int midiChannel, float gainReductionDb)>;

    FirmwareComms();
    ~FirmwareComms() override;

    juce::StringArray getMidiInputNames() const;
    juce::StringArray getMidiOutputNames() const;

    bool connect (const juce::String& inputName, const juce::String& outputName);
    void disconnect();
    bool isConnected() const { return midiOutput != nullptr; }

    void readAll (AppState& state);
    bool writeParameter (ParamId id, float normalised);

    void setGainReductionCallback (GainReductionCallback cb) { gainReductionCallback = std::move (cb); }
    void pollGainReduction();

private:
    void handleIncomingMidiMessage (juce::MidiInput* source,
                                    const juce::MidiMessage& message) override;

    std::unique_ptr<juce::MidiInput> midiInput;
    std::unique_ptr<juce::MidiOutput> midiOutput;
    GainReductionCallback gainReductionCallback;
    juce::CriticalSection midiLock;
};
