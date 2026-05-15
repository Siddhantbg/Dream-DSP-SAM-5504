#pragma once

#include "../AppState.h"
#include <cstdint>

enum class ParamFormat
{
    Nrpn14Bit,
    Nrpn28Bit
};

enum class ParamScale
{
    Gain14Bit,
    PhaseToggle,
    CompressorThreshold,
    CompressorAttack,
    CompressorRelease,
    CompressorMakeup,
    CompressorRatio,
    DelayTime28Bit,
    DelayGain14Bit,
    Frequency28Bit,
    EqGain14Bit,
    EqQ14Bit,
    Bool01,
    Linear01
};

struct ParamDescriptor
{
    ParamId id;
    uint8_t midiChannel;
    uint16_t nrpn;
    ParamFormat format;
    ParamScale scale;
};

class ParameterMap
{
public:
    static const ParamDescriptor* getDescriptor (ParamId id);
    static juce::String getDisplayName (ParamId id);
    static uint32_t normalisedToRaw (const ParamDescriptor& desc, float normalised);
    static float rawToNormalised (const ParamDescriptor& desc, uint32_t raw);
    static float getDefaultNormalised (ParamId id);
};
