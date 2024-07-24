/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
AudioPlayerAudioProcessorEditor::AudioPlayerAudioProcessorEditor (AudioPlayerAudioProcessor& p)
    : AudioProcessorEditor(&p), audioProcessor(p), openButton("Open"), playButton("Play"), stopButton("Stop")
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);

    //set buttons functionality with lambda functions 
    openButton.onClick = [this] {; };
    addAndMakeVisible(openButton);

    playButton.onClick = [this] {; };
    addAndMakeVisible(playButton);
    playButton.setColour(juce::TextButton::buttonColourId, juce::Colours::green);

    stopButton.onClick = [this] {; };
    addAndMakeVisible(stopButton);
    stopButton.setColour(juce::TextButton::buttonColourId, juce::Colours::red);
}

AudioPlayerAudioProcessorEditor::~AudioPlayerAudioProcessorEditor()
{
}

//==============================================================================
void AudioPlayerAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (juce::FontOptions (15.0f));
   // g.drawFittedText ("Hello World!", getLocalBounds(), juce::Justification::centred, 1);
}

void AudioPlayerAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    openButton.setBounds(10, 10, getWidth() - 20, 30);
    playButton.setBounds(10, 45, getWidth() - 20, 30);
    stopButton.setBounds(10, 80, getWidth() - 20, 30);

}
