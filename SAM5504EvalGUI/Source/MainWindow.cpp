#include "MainWindow.h"

MainWindow::MainWindow (ApplicationController& controller)
    : DocumentWindow ("SAM5504 Eval Board",
                      juce::Desktop::getInstance().getDefaultLookAndFeel()
                          .findColour (juce::ResizableWindow::backgroundColourId),
                      DocumentWindow::allButtons),
      appController (controller),
      mainComponent (controller)
{
    setUsingNativeTitleBar (true);
    setContentNonOwned (&mainComponent, true);
    centreWithSize (mainComponent.getWidth(), mainComponent.getHeight());
    setVisible (true);
}

void MainWindow::closeButtonPressed()
{
    juce::JUCEApplication::getInstance()->systemRequestedQuit();
}
