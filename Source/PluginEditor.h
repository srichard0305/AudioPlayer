/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class AudioPlayerAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    AudioPlayerAudioProcessorEditor (AudioPlayerAudioProcessor&);
    ~AudioPlayerAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

   ;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    AudioPlayerAudioProcessor& audioProcessor;

    juce::TextButton openButton;
    juce::TextButton playButton;
    juce::TextButton stopButton;

    void openButtonClicked();
    void playButtonClicked();
    void stopButtonClicked();
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AudioPlayerAudioProcessorEditor)


};
