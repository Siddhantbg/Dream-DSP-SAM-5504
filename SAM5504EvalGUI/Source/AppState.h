#pragma once

#include <array>
#include <JuceHeader.h>

enum class ParamId : int
{
    Input_LeftGain,
    Input_RightGain,
    Input_LeftMute,
    Input_RightMute,

    LSub_OutputGain,
    LSub_CompThreshold,
    LSub_CompAttack,
    LSub_CompRelease,
    LSub_CompMakeup,
    LSub_CompRatio,
    LSub_Muted,

    LMid_DelayTime,
    LMid_DelayGain,
    LMid_DelayPhase,
    LMid_OutputGain,
    LMid_Muted,

    RSub_OutputGain,
    RSub_CompThreshold,
    RSub_CompAttack,
    RSub_CompRelease,
    RSub_CompMakeup,
    RSub_CompRatio,
    RSub_Muted,

    RMid_DelayTime,
    RMid_DelayGain,
    RMid_DelayPhase,
    RMid_OutputGain,
    RMid_Muted,

    LSub_EqFreq0, LSub_EqGain0, LSub_EqQ0,
    LSub_EqFreq1, LSub_EqGain1, LSub_EqQ1,
    LSub_EqFreq2, LSub_EqGain2, LSub_EqQ2,

    RSub_EqFreq0, RSub_EqGain0, RSub_EqQ0,
    RSub_EqFreq1, RSub_EqGain1, RSub_EqQ1,
    RSub_EqFreq2, RSub_EqGain2, RSub_EqQ2,

    Input_CrossoverFreq,
    Input_EqFreq0, Input_EqGain0, Input_EqQ0,

    Count
};

struct AppState
{
    struct EQBand
    {
        float freqHz = 1000.0f;
        float gainDB = 0.0f;
        float Q = 0.707f;
        juce::String type { "Peak" };
    };

    struct ChannelState
    {
        float outputGain = 1.0f;
        bool muted = false;
        float prevGain = 1.0f;
        std::array<EQBand, 3> eqBands {};
        float compThreshold = -24.0f;
        float compAttack = 10.0f;
        float compRelease = 100.0f;
        float compMakeup = 0.0f;
        float compRatio = 4.0f;
        float delayTimeMs = 0.0f;
        float delayGain = 0.0f;
        bool phaseInverted = false;
        float crossoverFreq = 1000.0f;
        float gainReductionDb = 0.0f;
    };

    ChannelState lSub;
    ChannelState lMid;
    ChannelState rSub;
    ChannelState rMid;

    float inputLeftGain = 1.0f;
    float inputRightGain = 1.0f;
    bool inputLeftMuted = false;
    bool inputRightMuted = false;
    float inputLeftPrevGain = 1.0f;
    float inputRightPrevGain = 1.0f;
    float inputCrossoverFreq = 1000.0f;
    std::array<EQBand, 3> inputEqBands {};

    ChannelState& channelForParam (ParamId id);
    const ChannelState& channelForParam (ParamId id) const;

    void applyDefaultsFromPresets();
    float getNormalised (ParamId id) const;
    void setFromNormalised (ParamId id, float normalised);
};
