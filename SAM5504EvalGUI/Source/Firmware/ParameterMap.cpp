#include "ParameterMap.h"

namespace
{
constexpr uint32_t kGainUnityRaw = 14847u;
constexpr uint32_t k14BitMax = 0x3FFFu;

const ParamDescriptor kDescriptors[] =
{
    { ParamId::Input_LeftGain,       0, 0x0100, ParamFormat::Nrpn14Bit, ParamScale::Gain14Bit },
    { ParamId::Input_RightGain,      2, 0x0100, ParamFormat::Nrpn14Bit, ParamScale::Gain14Bit },

    { ParamId::LSub_OutputGain,      0, 0x0100, ParamFormat::Nrpn14Bit, ParamScale::Gain14Bit },
    { ParamId::LSub_CompThreshold,   0, 0x0502, ParamFormat::Nrpn14Bit, ParamScale::CompressorThreshold },
    { ParamId::LSub_CompAttack,      0, 0x0400, ParamFormat::Nrpn14Bit, ParamScale::CompressorAttack },
    { ParamId::LSub_CompRelease,     0, 0x0401, ParamFormat::Nrpn14Bit, ParamScale::CompressorRelease },
    { ParamId::LSub_CompMakeup,      0, 0x0504, ParamFormat::Nrpn14Bit, ParamScale::CompressorMakeup },
    { ParamId::LSub_CompRatio,       0, 0x0503, ParamFormat::Nrpn14Bit, ParamScale::CompressorRatio },

    { ParamId::LMid_DelayTime,       1, 0x0101, ParamFormat::Nrpn28Bit, ParamScale::DelayTime28Bit },
    { ParamId::LMid_DelayGain,       1, 0x0102, ParamFormat::Nrpn14Bit, ParamScale::DelayGain14Bit },
    { ParamId::LMid_DelayPhase,      1, 0x0103, ParamFormat::Nrpn14Bit, ParamScale::PhaseToggle },
    { ParamId::LMid_OutputGain,      1, 0x0202, ParamFormat::Nrpn14Bit, ParamScale::Gain14Bit },

    { ParamId::RSub_OutputGain,      2, 0x0100, ParamFormat::Nrpn14Bit, ParamScale::Gain14Bit },
    { ParamId::RSub_CompThreshold,   2, 0x0502, ParamFormat::Nrpn14Bit, ParamScale::CompressorThreshold },
    { ParamId::RSub_CompAttack,      2, 0x0400, ParamFormat::Nrpn14Bit, ParamScale::CompressorAttack },
    { ParamId::RSub_CompRelease,     2, 0x0401, ParamFormat::Nrpn14Bit, ParamScale::CompressorRelease },
    { ParamId::RSub_CompMakeup,      2, 0x0504, ParamFormat::Nrpn14Bit, ParamScale::CompressorMakeup },
    { ParamId::RSub_CompRatio,       2, 0x0503, ParamFormat::Nrpn14Bit, ParamScale::CompressorRatio },

    { ParamId::RMid_DelayTime,       3, 0x0101, ParamFormat::Nrpn28Bit, ParamScale::DelayTime28Bit },
    { ParamId::RMid_DelayGain,       3, 0x0102, ParamFormat::Nrpn14Bit, ParamScale::DelayGain14Bit },
    { ParamId::RMid_DelayPhase,      3, 0x0103, ParamFormat::Nrpn14Bit, ParamScale::PhaseToggle },
    { ParamId::RMid_OutputGain,      3, 0x0202, ParamFormat::Nrpn14Bit, ParamScale::Gain14Bit },

    { ParamId::LSub_EqFreq0,         0, 0x0241, ParamFormat::Nrpn28Bit, ParamScale::Frequency28Bit },
    { ParamId::LSub_EqGain0,         0, 0x0260, ParamFormat::Nrpn14Bit, ParamScale::EqGain14Bit },
    { ParamId::LSub_EqQ0,            0, 0x0222, ParamFormat::Nrpn14Bit, ParamScale::EqQ14Bit },
    { ParamId::LSub_EqFreq1,         0, 0x0241, ParamFormat::Nrpn28Bit, ParamScale::Frequency28Bit },
    { ParamId::LSub_EqGain1,         0, 0x0260, ParamFormat::Nrpn14Bit, ParamScale::EqGain14Bit },
    { ParamId::LSub_EqQ1,            0, 0x0222, ParamFormat::Nrpn14Bit, ParamScale::EqQ14Bit },
    { ParamId::LSub_EqFreq2,         0, 0x0241, ParamFormat::Nrpn28Bit, ParamScale::Frequency28Bit },
    { ParamId::LSub_EqGain2,         0, 0x0260, ParamFormat::Nrpn14Bit, ParamScale::EqGain14Bit },
    { ParamId::LSub_EqQ2,            0, 0x0222, ParamFormat::Nrpn14Bit, ParamScale::EqQ14Bit },

    { ParamId::RSub_EqFreq0,         2, 0x0241, ParamFormat::Nrpn28Bit, ParamScale::Frequency28Bit },
    { ParamId::RSub_EqGain0,         2, 0x0260, ParamFormat::Nrpn14Bit, ParamScale::EqGain14Bit },
    { ParamId::RSub_EqQ0,            2, 0x0222, ParamFormat::Nrpn14Bit, ParamScale::EqQ14Bit },
    { ParamId::RSub_EqFreq1,         2, 0x0241, ParamFormat::Nrpn28Bit, ParamScale::Frequency28Bit },
    { ParamId::RSub_EqGain1,         2, 0x0260, ParamFormat::Nrpn14Bit, ParamScale::EqGain14Bit },
    { ParamId::RSub_EqQ1,            2, 0x0222, ParamFormat::Nrpn14Bit, ParamScale::EqQ14Bit },
    { ParamId::RSub_EqFreq2,         2, 0x0241, ParamFormat::Nrpn28Bit, ParamScale::Frequency28Bit },
    { ParamId::RSub_EqGain2,         2, 0x0260, ParamFormat::Nrpn14Bit, ParamScale::EqGain14Bit },
    { ParamId::RSub_EqQ2,            2, 0x0222, ParamFormat::Nrpn14Bit, ParamScale::EqQ14Bit },
};

float dbToNorm (float db, float minDb, float maxDb)
{
    return juce::jlimit (0.0f, 1.0f, (db - minDb) / (maxDb - minDb));
}

float normToDb (float norm, float minDb, float maxDb)
{
    return minDb + norm * (maxDb - minDb);
}
} // namespace

const ParamDescriptor* ParameterMap::getDescriptor (ParamId id)
{
    for (const auto& d : kDescriptors)
        if (d.id == id)
            return &d;

    return nullptr;
}

juce::String ParameterMap::getDisplayName (ParamId id)
{
    switch (id)
    {
        case ParamId::Input_LeftGain:       return "Input L Gain";
        case ParamId::Input_RightGain:      return "Input R Gain";
        case ParamId::LSub_OutputGain:      return "L Sub Output";
        case ParamId::LSub_CompThreshold:   return "L Sub Threshold";
        case ParamId::LSub_CompAttack:      return "L Sub Attack";
        case ParamId::LSub_CompRelease:     return "L Sub Release";
        case ParamId::LSub_CompMakeup:      return "L Sub Makeup";
        case ParamId::LMid_DelayTime:       return "L Mid Delay";
        case ParamId::LMid_DelayGain:       return "L Mid Delay Gain";
        case ParamId::RSub_OutputGain:      return "R Sub Output";
        case ParamId::RSub_CompThreshold:   return "R Sub Threshold";
        case ParamId::RSub_CompAttack:      return "R Sub Attack";
        case ParamId::RSub_CompRelease:     return "R Sub Release";
        case ParamId::RSub_CompMakeup:      return "R Sub Makeup";
        case ParamId::RMid_DelayTime:       return "R Mid Delay";
        case ParamId::RMid_DelayGain:       return "R Mid Delay Gain";
        default: break;
    }
    return juce::String (static_cast<int> (id));
}

uint32_t ParameterMap::normalisedToRaw (const ParamDescriptor& desc, float normalised)
{
    const auto n = juce::jlimit (0.0f, 1.0f, normalised);

    switch (desc.scale)
    {
        case ParamScale::Gain14Bit:
        case ParamScale::DelayGain14Bit:
            return static_cast<uint32_t> (n * static_cast<float> (k14BitMax));

        case ParamScale::CompressorThreshold:
            return static_cast<uint32_t> (dbToNorm (normToDb (n, -60.0f, 0.0f), -60.0f, 0.0f) * static_cast<float> (k14BitMax));

        case ParamScale::CompressorAttack:
            return static_cast<uint32_t> (juce::jmap (n, 0.1f, 500.0f) / 500.0f * static_cast<float> (k14BitMax));

        case ParamScale::CompressorRelease:
            return static_cast<uint32_t> (juce::jmap (n, 10.0f, 2000.0f) / 2000.0f * static_cast<float> (k14BitMax));

        case ParamScale::CompressorMakeup:
            return static_cast<uint32_t> (dbToNorm (normToDb (n, 0.0f, 24.0f), 0.0f, 24.0f) * static_cast<float> (k14BitMax));

        case ParamScale::CompressorRatio:
            return static_cast<uint32_t> (juce::jmap (n, 1.0f, 20.0f) / 20.0f * static_cast<float> (k14BitMax));

        case ParamScale::PhaseToggle:
            return n >= 0.5f ? 1u : 0u;

        case ParamScale::DelayTime28Bit:
            return static_cast<uint32_t> (n * static_cast<float> (0x07FFFFFFu));

        case ParamScale::Frequency28Bit:
        {
            const float hz = juce::jlimit (20.0f, 20000.0f, juce::jmap (n, 20.0f, 20000.0f));
            return static_cast<uint32_t> (std::log2 (hz / 20.0f) / std::log2 (1000.0f) * static_cast<float> (0x07FFFFFFu));
        }

        case ParamScale::EqGain14Bit:
            return static_cast<uint32_t> (dbToNorm (normToDb (n, -24.0f, 24.0f), -24.0f, 24.0f) * static_cast<float> (k14BitMax));

        case ParamScale::EqQ14Bit:
            return static_cast<uint32_t> (juce::jmap (n, 0.1f, 10.0f) / 10.0f * static_cast<float> (k14BitMax));

        case ParamScale::Bool01:
            return n >= 0.5f ? 1u : 0u;

        case ParamScale::Linear01:
        default:
            return static_cast<uint32_t> (n * static_cast<float> (k14BitMax));
    }
}

float ParameterMap::rawToNormalised (const ParamDescriptor& desc, uint32_t raw)
{
    switch (desc.scale)
    {
        case ParamScale::Gain14Bit:
        case ParamScale::DelayGain14Bit:
            return static_cast<float> (raw) / static_cast<float> (k14BitMax);

        case ParamScale::CompressorThreshold:
            return dbToNorm (normToDb (static_cast<float> (raw) / static_cast<float> (k14BitMax), -60.0f, 0.0f), -60.0f, 0.0f);

        case ParamScale::DelayTime28Bit:
            return static_cast<float> (raw) / static_cast<float> (0x07FFFFFFu);

        default:
            return static_cast<float> (raw) / static_cast<float> (k14BitMax);
    }
}

float ParameterMap::getDefaultNormalised (ParamId id)
{
    if (id == ParamId::Input_LeftGain || id == ParamId::Input_RightGain
        || id == ParamId::LSub_OutputGain || id == ParamId::RSub_OutputGain
        || id == ParamId::LMid_OutputGain || id == ParamId::RMid_OutputGain
        || id == ParamId::LMid_DelayGain || id == ParamId::RMid_DelayGain)
        return static_cast<float> (kGainUnityRaw) / static_cast<float> (k14BitMax);

    if (id == ParamId::LSub_CompThreshold || id == ParamId::RSub_CompThreshold)
        return dbToNorm (-24.0f, -60.0f, 0.0f);

    return 0.5f;
}
