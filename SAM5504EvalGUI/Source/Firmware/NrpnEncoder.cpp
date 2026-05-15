#include "NrpnEncoder.h"

void NrpnEncoder::send14BitNrpn (juce::MidiOutput& output,
                                 const int midiChannel,
                                 const uint16_t nrpn,
                                 const uint32_t rawValue)
{
    const auto value14 = juce::jlimit<uint32_t> (0, 0x3FFFu, rawValue);
    const auto msb = static_cast<int> ((value14 >> 7) & 0x7F);
    const auto lsb = static_cast<int> (value14 & 0x7F);

    output.sendMessageNow (juce::MidiMessage::controllerEvent (midiChannel, 99, (nrpn >> 7) & 0x7F));
    output.sendMessageNow (juce::MidiMessage::controllerEvent (midiChannel, 98, nrpn & 0x7F));
    output.sendMessageNow (juce::MidiMessage::controllerEvent (midiChannel, 6, msb));
    output.sendMessageNow (juce::MidiMessage::controllerEvent (midiChannel, 38, lsb));

    DBG ("NRPN ch=" + juce::String (midiChannel)
         + " nrpn=0x" + juce::String::toHexString ((int) nrpn)
         + " val=" + juce::String ((int) value14));
}

void NrpnEncoder::send28BitNrpnSysEx (juce::MidiOutput& output,
                                      const int midiChannel,
                                      const uint16_t nrpn,
                                      const uint32_t rawValue)
{
    const auto value28 = juce::jlimit<uint32_t> (0, 0x07FFFFFFu, rawValue);
    juce::uint8 data[5] {};

    data[0] = static_cast<juce::uint8> ((value28 >> 21) & 0x7F);
    data[1] = static_cast<juce::uint8> ((value28 >> 14) & 0x7F);
    data[2] = static_cast<juce::uint8> ((value28 >> 7) & 0x7F);
    data[3] = static_cast<juce::uint8> (value28 & 0x7F);

    const juce::uint8 sysexBytes[] =
    {
        0x00, 0x20, 0x00, 0x3D,
        static_cast<juce::uint8> (midiChannel),
        static_cast<juce::uint8> ((nrpn >> 8) & 0x7F),
        static_cast<juce::uint8> (nrpn & 0x7F),
        4,
        data[0], data[1], data[2], data[3]
    };

    output.sendMessageNow (juce::MidiMessage::createSysExMessage (sysexBytes, (int) sizeof (sysexBytes)));

    DBG ("SysEx NRPN ch=" + juce::String (midiChannel)
         + " nrpn=0x" + juce::String::toHexString ((int) nrpn)
         + " val28=" + juce::String ((int) value28));
}

void NrpnEncoder::sendParameter (juce::MidiOutput& output,
                                 const ParamDescriptor& desc,
                                 const float normalised)
{
    const auto raw = ParameterMap::normalisedToRaw (desc, normalised);

    if (desc.format == ParamFormat::Nrpn28Bit)
        send28BitNrpnSysEx (output, desc.midiChannel, desc.nrpn, raw);
    else
        send14BitNrpn (output, desc.midiChannel, desc.nrpn, raw);
}

void NrpnEncoder::requestGainReduction (juce::MidiOutput& output, const int midiChannel)
{
    send14BitNrpn (output, midiChannel, 0x0500, 0);
}
