#include <iostream>
#include "LowFreqOscillator.h"

LowFreqOscillator::LowFreqOscillator() : frequency(440), waveform(0), modDepth(0)
{
    for (int c{10}; c < 100; ++c)
    {   
        frequency = c;
    }

    tapTempo = false;
}

void LowFreqOscillator::enable()
{
    isActive = true;
}

void LowFreqOscillator::disable()
{
    isActive = false;
}

void LowFreqOscillator::setParams(double freq, int wave, int mod)
{
    frequency = freq;
    waveform = wave;
    modDepth = mod;
}

double LowFreqOscillator::getFrequency()
{
    return this->frequency;
}

void LowFreqOscillator::printFrequencyMsg()
{
    std::cout << "lfo's Frequency is: " << this->getFrequency() << std::endl;    
}

int LowFreqOscillator::getModDepth()
{
    return this->modDepth;
}

void LowFreqOscillator::printModDepthMsg()
{
    std::cout << "lfo's Mod Depth is: " << this->getModDepth() << std::endl;    
}

