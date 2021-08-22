#pragma once
#include <array>
#include "LeakedObjectDetector.h"
#include "Voice.h"
#include "LowFreqOscillator.h"
/*
 new UDT 4:
 */
struct SynthMoog
{
    std::array<Voice, 4> voices;
    LowFreqOscillator lfo;
    EnvelopeGenerator envGen;

    SynthMoog();
    ~SynthMoog();

    void setVoiceFreq(unsigned int VoiceNum, float freq = 440);
    void setADSR(int attack, int decay, int sustain, int release);
    void setLFO(double frequency, int waveform, int modDepth);
    void playChord();
    std::string getModelName();

    void printLFOFrequency();

    JUCE_LEAK_DETECTOR(SynthMoog)
};
