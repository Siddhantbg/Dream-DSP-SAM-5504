#pragma once

#include "ParameterMap.h"
#include <JuceHeader.h>

class NrpnEncoder
{
public:
    static void send14BitNrpn (juce::MidiOutput& output,
                               int midiChannel,
                               uint16_t nrpn,
                               uint32_t rawValue);

    static void send28BitNrpnSysEx (juce::MidiOutput& output,
                                    int midiChannel,
                                    uint16_t nrpn,
                                    uint32_t rawValue);

    static void sendParameter (juce::MidiOutput& output,
                               const ParamDescriptor& desc,
                               float normalised);

    static void requestGainReduction (juce::MidiOutput& output, int midiChannel);
};
