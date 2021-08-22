#include "Wrappers.h"

#include "KeithEmerson.h"
// This is the problem here and the problem is specific to the nested class
EnvelopeGenerator::VCAWrapper::VCAWrapper(EnvelopeGenerator::VCA* _udt) :
udt1(_udt)
{

}

EnvelopeGenerator::VCAWrapper::~VCAWrapper()
{
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

