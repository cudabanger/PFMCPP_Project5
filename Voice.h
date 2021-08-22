#pragma once
#include "LeakedObjectDetector.h"
#include "EnvelopeGenerator.h"
/*
 UDT 3: With Nested UDT 2 of 2
 */
struct Voice
{
    Voice();

    void initialize();
    void playSound();
    void mute();
    void printFrequencyMsg();
    void printAttackMsg();

    struct Oscillator
    {
        Oscillator();

        void setFrequency(float freq);
        float getFrequency();
        void setWaveform(int freq);
        void setOscType(int type);

        EnvelopeGenerator ADSR;
        float frequency;
        int oscType, waveform;
        bool sync;

        JUCE_LEAK_DETECTOR(Oscillator)
    };

    struct OscillatorWrapper
    {
        OscillatorWrapper(Oscillator* _udt) : udt1(_udt) { }
        ~OscillatorWrapper() { delete udt1; }
        Oscillator* udt1 = nullptr;
    };

    OscillatorWrapper oscWrapper1{ new Oscillator };
    OscillatorWrapper oscWrapper2{ new Oscillator };
    OscillatorWrapper oscWrapper3{ new Oscillator };
    OscillatorWrapper oscWrapper4{ new Oscillator };

    bool isMute; 

    JUCE_LEAK_DETECTOR(Voice)
};
