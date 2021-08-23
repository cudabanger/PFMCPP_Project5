#pragma once
#include "LeakedObjectDetector.h"
/*
 UDT 2:
 */
struct LowFreqOscillator
{
    double  frequency;
    int     waveform; 
    int     modDepth;
    bool    tapTempo {false};
    bool    isActive {false};

    LowFreqOscillator();

    void enable();
    void disable();
    void setParams(double frequency, int waveform, int modDepth);
    double getFrequency();
    int getModDepth(); 
    void printFrequencyMsg();
    void printModDepthMsg();

    JUCE_LEAK_DETECTOR(LowFreqOscillator)
};

