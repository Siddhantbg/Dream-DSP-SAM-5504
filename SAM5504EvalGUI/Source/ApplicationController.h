#pragma once

#include "AppState.h"
#include "DSP/HostAudioEngine.h"
#include "Firmware/FirmwareComms.h"
#include <functional>
#include <JuceHeader.h>

class ApplicationController
{
public:
    ApplicationController();

    AppState& getState() { return state; }
    const AppState& getState() const { return state; }

    FirmwareComms& getFirmwareComms() { return firmwareComms; }
    HostAudioEngine& getHostAudioEngine() { return hostAudioEngine; }

    void initialise();
    void shutdown();

    void setParameter (ParamId id, float normalised);
    void setMute (bool leftChannel, bool muted);

    void connectMidi (const juce::String& inputName, const juce::String& outputName);
    void disconnectMidi();
    void pushStateToFirmware();

    std::function<void()> onStateChanged;

private:
    AppState state;
    FirmwareComms firmwareComms;
    HostAudioEngine hostAudioEngine;
};
