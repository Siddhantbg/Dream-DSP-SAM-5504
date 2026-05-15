#include "ApplicationController.h"

ApplicationController::ApplicationController() = default;

void ApplicationController::initialise()
{
    firmwareComms.readAll (state);
    hostAudioEngine.prepare (48000.0);
    hostAudioEngine.start();

    firmwareComms.setGainReductionCallback ([this] (int channel, float grDb)
    {
        if (channel == 0)
            state.lSub.gainReductionDb = grDb;
        else if (channel == 2)
            state.rSub.gainReductionDb = grDb;

        if (onStateChanged)
            onStateChanged();
    });
}

void ApplicationController::shutdown()
{
    hostAudioEngine.stop();
    firmwareComms.disconnect();
}

void ApplicationController::setParameter (const ParamId id, const float normalised)
{
    state.setFromNormalised (id, normalised);
    firmwareComms.writeParameter (id, normalised);
    hostAudioEngine.setParameter (id, normalised);

    if (onStateChanged)
        onStateChanged();
}

void ApplicationController::setMute (const bool leftChannel, const bool muted)
{
    if (leftChannel)
    {
        if (muted && ! state.inputLeftMuted)
            state.inputLeftPrevGain = state.inputLeftGain;

        state.inputLeftMuted = muted;
        setParameter (ParamId::Input_LeftGain, muted ? 0.0f : state.inputLeftPrevGain);
        hostAudioEngine.setChannelMute (0, muted, state.inputLeftPrevGain);
    }
    else
    {
        if (muted && ! state.inputRightMuted)
            state.inputRightPrevGain = state.inputRightGain;

        state.inputRightMuted = muted;
        setParameter (ParamId::Input_RightGain, muted ? 0.0f : state.inputRightPrevGain);
        hostAudioEngine.setChannelMute (1, muted, state.inputRightPrevGain);
    }
}

void ApplicationController::connectMidi (const juce::String& inputName, const juce::String& outputName)
{
    if (firmwareComms.connect (inputName, outputName))
        pushStateToFirmware();
}

void ApplicationController::pushStateToFirmware()
{
    const ParamId ids[] =
    {
        ParamId::Input_LeftGain, ParamId::Input_RightGain,
        ParamId::LSub_OutputGain, ParamId::LSub_CompThreshold,
        ParamId::LSub_CompAttack, ParamId::LSub_CompRelease, ParamId::LSub_CompMakeup,
        ParamId::LMid_DelayTime, ParamId::LMid_DelayGain,
        ParamId::RSub_OutputGain, ParamId::RSub_CompThreshold,
        ParamId::RSub_CompAttack, ParamId::RSub_CompRelease, ParamId::RSub_CompMakeup,
        ParamId::RMid_DelayTime, ParamId::RMid_DelayGain
    };

    for (const auto id : ids)
        firmwareComms.writeParameter (id, state.getNormalised (id));
}

void ApplicationController::disconnectMidi()
{
    firmwareComms.disconnect();
}
