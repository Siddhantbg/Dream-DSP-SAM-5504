#include "MainWindow.h"
#include <JuceHeader.h>

class Sam5504EvalApplication : public juce::JUCEApplication
{
public:
    const juce::String getApplicationName() override       { return "SAM5504 Eval Board"; }
    const juce::String getApplicationVersion() override    { return "1.0.0"; }
    bool moreThanOneInstanceAllowed() override             { return false; }

    void initialise (const juce::String&) override
    {
        controller.initialise();
        mainWindow = std::make_unique<MainWindow> (controller);
    }

    void shutdown() override
    {
        mainWindow = nullptr;
        controller.shutdown();
    }

private:
    ApplicationController controller;
    std::unique_ptr<MainWindow> mainWindow;
};

START_JUCE_APPLICATION (Sam5504EvalApplication)
