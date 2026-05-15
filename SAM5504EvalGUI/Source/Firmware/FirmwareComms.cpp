#include "FirmwareComms.h"
#include "NrpnEncoder.h"

FirmwareComms::FirmwareComms() = default;

FirmwareComms::~FirmwareComms()
{
    disconnect();
}

juce::StringArray FirmwareComms::getMidiInputNames() const
{
    juce::StringArray names;

    for (const auto& dev : juce::MidiInput::getAvailableDevices())
        names.add (dev.name);

    return names;
}

juce::StringArray FirmwareComms::getMidiOutputNames() const
{
    juce::StringArray names;

    for (const auto& dev : juce::MidiOutput::getAvailableDevices())
        names.add (dev.name);

    return names;
}

bool FirmwareComms::connect (const juce::String& inputName, const juce::String& outputName)
{
    disconnect();

    for (const auto& dev : juce::MidiInput::getAvailableDevices())
    {
        if (dev.name == inputName)
        {
            midiInput = juce::MidiInput::openDevice (dev.identifier, this);
            break;
        }
    }

    for (const auto& dev : juce::MidiOutput::getAvailableDevices())
    {
        if (dev.name == outputName)
        {
            midiOutput = juce::MidiOutput::openDevice (dev.identifier);
            break;
        }
    }

    if (midiInput != nullptr)
        midiInput->start();

    return midiOutput != nullptr;
}

void FirmwareComms::disconnect()
{
    if (midiInput != nullptr)
    {
        midiInput->stop();
        midiInput.reset();
    }

    midiOutput.reset();
}

void FirmwareComms::readAll (AppState& state)
{
    state.applyDefaultsFromPresets();
}

bool FirmwareComms::writeParameter (const ParamId id, const float normalised)
{
    const juce::ScopedLock sl (midiLock);

    if (midiOutput == nullptr)
        return false;

    const auto* desc = ParameterMap::getDescriptor (id);
    if (desc == nullptr)
        return false;

    NrpnEncoder::sendParameter (*midiOutput, *desc, normalised);
    return true;
}

void FirmwareComms::pollGainReduction()
{
    const juce::ScopedLock sl (midiLock);

    if (midiOutput == nullptr)
        return;

    NrpnEncoder::requestGainReduction (*midiOutput, 0);
    NrpnEncoder::requestGainReduction (*midiOutput, 2);
}

void FirmwareComms::handleIncomingMidiMessage (juce::MidiInput*,
                                               const juce::MidiMessage& message)
{
    if (! message.isSysEx())
        return;

    const auto* data = message.getSysExData();
    const int size = message.getSysExDataSize();

    if (size < 6 || data[0] != 0x00 || data[1] != 0x20)
        return;

    if (gainReductionCallback != nullptr)
    {
        const int channel = data[2];
        const float gr = static_cast<float> (data[5]) * -0.5f;
        gainReductionCallback (channel, gr);
    }
}
