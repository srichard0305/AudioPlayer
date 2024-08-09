/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
AudioPlayerAudioProcessorEditor::AudioPlayerAudioProcessorEditor(AudioPlayerAudioProcessor& p)
    : AudioProcessorEditor(&p), audioProcessor(p),
      sliderAttachment(audioProcessor.apvts, "Gain Slider", gainSlider)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (500, 300);

    addAndMakeVisible(&openButton);
    openButton.setButtonText("Open");
    openButton.onClick = [this] { openButtonClicked(); };
    
    addAndMakeVisible(&playButton);
    playButton.setColour(juce::TextButton::buttonColourId, juce::Colours::green);
    playButton.setButtonText("Play");
    playButton.onClick = [this] { playButtonClicked(); };
    playButton.setEnabled(false);
 
    addAndMakeVisible(&stopButton);
    stopButton.setColour(juce::TextButton::buttonColourId, juce::Colours::red);
    stopButton.setButtonText("Stop");
    stopButton.onClick = [this] { stopButtonClicked(); };
    stopButton.setEnabled(false);

    addAndMakeVisible(&gainSlider);
    gainSlider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
   
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
   

}

void AudioPlayerAudioProcessorEditor::openButtonClicked() {
    audioProcessor.openFile();
    playButton.setEnabled(true);
}
void AudioPlayerAudioProcessorEditor::playButtonClicked() {
    audioProcessor.playFile();
    playButton.setEnabled(false);
    stopButton.setEnabled(true);
}
void AudioPlayerAudioProcessorEditor::stopButtonClicked() {
    audioProcessor.stopFile();
    stopButton.setEnabled(false);
    playButton.setEnabled(true);
}

void AudioPlayerAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    openButton.setBounds(10, 190, getWidth() - 300, 30);
    playButton.setBounds(10, 225, getWidth() - 300, 30);
    stopButton.setBounds(10, 260, getWidth() - 300, 30);

    gainSlider.setBounds(300, 190, 20, 100);

}
