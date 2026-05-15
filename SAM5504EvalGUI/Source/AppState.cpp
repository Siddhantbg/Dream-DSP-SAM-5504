#include "AppState.h"
#include "Firmware/ParameterMap.h"

AppState::ChannelState& AppState::channelForParam (const ParamId id)
{
    switch (id)
    {
        case ParamId::LSub_OutputGain:
        case ParamId::LSub_CompThreshold:
        case ParamId::LSub_CompAttack:
        case ParamId::LSub_CompRelease:
        case ParamId::LSub_CompMakeup:
        case ParamId::LSub_CompRatio:
        case ParamId::LSub_Muted:
        case ParamId::LSub_EqFreq0:
        case ParamId::LSub_EqGain0:
        case ParamId::LSub_EqQ0:
        case ParamId::LSub_EqFreq1:
        case ParamId::LSub_EqGain1:
        case ParamId::LSub_EqQ1:
        case ParamId::LSub_EqFreq2:
        case ParamId::LSub_EqGain2:
        case ParamId::LSub_EqQ2:
            return lSub;

        case ParamId::LMid_DelayTime:
        case ParamId::LMid_DelayGain:
        case ParamId::LMid_DelayPhase:
        case ParamId::LMid_OutputGain:
        case ParamId::LMid_Muted:
            return lMid;

        case ParamId::RSub_OutputGain:
        case ParamId::RSub_CompThreshold:
        case ParamId::RSub_CompAttack:
        case ParamId::RSub_CompRelease:
        case ParamId::RSub_CompMakeup:
        case ParamId::RSub_CompRatio:
        case ParamId::RSub_Muted:
        case ParamId::RSub_EqFreq0:
        case ParamId::RSub_EqGain0:
        case ParamId::RSub_EqQ0:
        case ParamId::RSub_EqFreq1:
        case ParamId::RSub_EqGain1:
        case ParamId::RSub_EqQ1:
        case ParamId::RSub_EqFreq2:
        case ParamId::RSub_EqGain2:
        case ParamId::RSub_EqQ2:
            return rSub;

        case ParamId::RMid_DelayTime:
        case ParamId::RMid_DelayGain:
        case ParamId::RMid_DelayPhase:
        case ParamId::RMid_OutputGain:
        case ParamId::RMid_Muted:
            return rMid;

        default:
            return lSub;
    }
}

const AppState::ChannelState& AppState::channelForParam (const ParamId id) const
{
    return const_cast<AppState*> (this)->channelForParam (id);
}

void AppState::applyDefaultsFromPresets()
{
    inputLeftGain = inputRightGain = 1.0f;
    lSub.outputGain = rSub.outputGain = lMid.outputGain = rMid.outputGain = 1.0f;
    lSub.compThreshold = rSub.compThreshold = -24.0f;
    lSub.compAttack = rSub.compAttack = 10.0f;
    lSub.compRelease = rSub.compRelease = 100.0f;
    lSub.compRatio = 20.0f;
    rSub.compRatio = 4.0f;
    inputCrossoverFreq = 1000.0f;

    for (auto& ch : { &lSub, &lMid, &rSub, &rMid })
    {
        ch->eqBands[0].freqHz = 100.0f;
        ch->eqBands[1].freqHz = 1000.0f;
        ch->eqBands[2].freqHz = 8000.0f;
    }
}

float AppState::getNormalised (const ParamId id) const
{
    switch (id)
    {
        case ParamId::Input_LeftGain:   return inputLeftMuted ? 0.0f : inputLeftGain;
        case ParamId::Input_RightGain:  return inputRightMuted ? 0.0f : inputRightGain;
        case ParamId::LSub_OutputGain:  return lSub.muted ? 0.0f : lSub.outputGain;
        case ParamId::RSub_OutputGain:  return rSub.muted ? 0.0f : rSub.outputGain;
        case ParamId::LSub_CompThreshold:
            return juce::jlimit (0.0f, 1.0f, (lSub.compThreshold + 60.0f) / 60.0f);
        case ParamId::RSub_CompThreshold:
            return juce::jlimit (0.0f, 1.0f, (rSub.compThreshold + 60.0f) / 60.0f);
        case ParamId::LMid_DelayTime:
            return juce::jlimit (0.0f, 1.0f, lMid.delayTimeMs / 500.0f);
        case ParamId::RMid_DelayTime:
            return juce::jlimit (0.0f, 1.0f, rMid.delayTimeMs / 500.0f);
        case ParamId::LMid_DelayGain:
            return lMid.delayGain;
        case ParamId::RMid_DelayGain:
            return rMid.delayGain;
        default:
            return ParameterMap::getDefaultNormalised (id);
    }
}

void AppState::setFromNormalised (const ParamId id, const float normalised)
{
    const auto n = juce::jlimit (0.0f, 1.0f, normalised);

    switch (id)
    {
        case ParamId::Input_LeftGain:   inputLeftGain = n; break;
        case ParamId::Input_RightGain:  inputRightGain = n; break;
        case ParamId::LSub_OutputGain:  lSub.outputGain = n; break;
        case ParamId::RSub_OutputGain:  rSub.outputGain = n; break;
        case ParamId::LSub_CompThreshold:
            lSub.compThreshold = -60.0f + n * 60.0f;
            break;
        case ParamId::RSub_CompThreshold:
            rSub.compThreshold = -60.0f + n * 60.0f;
            break;
        case ParamId::LMid_DelayTime:
            lMid.delayTimeMs = n * 500.0f;
            break;
        case ParamId::RMid_DelayTime:
            rMid.delayTimeMs = n * 500.0f;
            break;
        case ParamId::LMid_DelayGain:
            lMid.delayGain = n;
            break;
        case ParamId::RMid_DelayGain:
            rMid.delayGain = n;
            break;
        default:
            break;
    }
}
