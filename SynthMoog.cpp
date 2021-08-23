#include <iostream>
#include "SynthMoog.h"

SynthMoog::SynthMoog()
{

}

SynthMoog::~SynthMoog()
{
    std::cout << "Calling DTOR - SynthMoog" << std::endl; 
}

void SynthMoog::setVoiceFreq(unsigned int voiceNum, float freq)
{
    if ( voiceNum <= 3 )
    {
        voices[voiceNum].oscWrapper1.udt1->setFrequency(freq);
        voices[voiceNum].oscWrapper2.udt1->setFrequency(freq);
        voices[voiceNum].oscWrapper3.udt1->setFrequency(freq);
        voices[voiceNum].oscWrapper4.udt1->setFrequency(freq);
    }
}

void SynthMoog::setADSR(int attack, int decay, int sustain, int release)
{
    envGen.setADSR(attack, decay, sustain, release);
}

void SynthMoog::setLFO(double frequency, int waveform, int modDepth)
{
    lfo.setParams(frequency, waveform, modDepth);
}

void SynthMoog::playChord()
{
    for(auto& voice : voices)
        voice.playSound();
}

std::string SynthMoog::getModelName()
{
    return "Emerson Moog Modular";
}

void SynthMoog::printLFOFrequency()
{
    std::cout << "Synth's LFO frequency is: " << this->lfo.getFrequency() << std::endl;
}
