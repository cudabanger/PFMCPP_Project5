#include "Wrappers.h"

#include "KeithEmerson.h"

VCAWrapper::VCAWrapper(EnvelopeGenerator::VCA* _udt) :
udt1(_udt)
{
    std::cout << "CTOR - VCAWrapper " << std::endl;
}

VCAWrapper::~VCAWrapper()
{
    std::cout << "DTOR - VCAWrapper " << std::endl;
    delete udt1;
}

////////////////////// Everything works from here.
EnvelopeGeneratorWrapper::EnvelopeGeneratorWrapper(EnvelopeGenerator* _udt) :
udt1(_udt)
{

}

EnvelopeGeneratorWrapper::~EnvelopeGeneratorWrapper()
{
    delete udt1;
}

LowFreqOscillatorWrapper::LowFreqOscillatorWrapper(LowFreqOscillator* _udt) :
udt1(_udt)
{

}

LowFreqOscillatorWrapper::~LowFreqOscillatorWrapper()
{
    delete udt1;
}

VoiceWrapper::VoiceWrapper(Voice* _udt) :
udt1(_udt)
{
}
VoiceWrapper::~VoiceWrapper()
{
    delete udt1;
}

SynthMoogWrapper::SynthMoogWrapper(SynthMoog* _udt) :
udt1(_udt)
{ 

}
SynthMoogWrapper::~SynthMoogWrapper()
{
    delete udt1;
}

KeithEmersonWrapper::KeithEmersonWrapper(KeithEmerson* _udt) :
udt1(_udt)
{
}

KeithEmersonWrapper::~KeithEmersonWrapper()
{
    delete udt1;
}

