#include "Voice.h"

Voice::Voice():isMute(true)
{
    initialize();
}

void Voice::initialize()
{
    oscWrapper1.udt1->setWaveform(1);
    oscWrapper2.udt1->setWaveform(2);
    oscWrapper3.udt1->setWaveform(1);
    oscWrapper4.udt1->setWaveform(2);
}

void Voice::playSound()
{
    // play C Maj 7
    oscWrapper1.udt1->setFrequency(130.813f);
    oscWrapper2.udt1->setFrequency(164.814f);
    oscWrapper3.udt1->setFrequency(195.998f);
    oscWrapper4.udt1->setFrequency(246.942f);
}

void Voice::mute()
{
    isMute = true;
}

Voice::Oscillator::Oscillator() : oscType(1), sync(false)
{
    for (int j{0}; j < 10; ++j)
    {  
        sync = true;  
    }
    ADSR.setADSR(0,0,0,0);
}

void Voice::Oscillator::setFrequency(float freq)
{
    frequency = freq;
}

void Voice::Oscillator::setWaveform(int wave)
{
    waveform = wave;
}

float Voice::Oscillator::getFrequency()
{
    return frequency;
}

void Voice::printAttackMsg()
{
    std::cout << "Voice's Oscillator 1 attack is: " << oscWrapper1.udt1->ADSR.getAttack() << 
    std::endl;
}

void Voice::printFrequencyMsg()
{
    std::cout << "Voice's Oscillator 1 frequency is: " << oscWrapper1.udt1->getFrequency() << std::endl;
}
