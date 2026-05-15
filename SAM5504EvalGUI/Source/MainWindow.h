#pragma once

#include "ApplicationController.h"
#include "MainComponent.h"
#include <JuceHeader.h>

class MainWindow : public juce::DocumentWindow
{
public:
    MainWindow (ApplicationController& controller);

    void closeButtonPressed() override;

private:
    ApplicationController& appController;
    MainComponent mainComponent;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainWindow)
};
