/*#pragma once

// forward declarations
//#include "EnvelopeGenerator.h"
struct EnvelopeGenerator;
struct VCA;

// definitions
struct VCAWrapper
{
    VCAWrapper(EnvelopeGenerator::VCA* _udt) : udt1(_udt) { }
    ~VCAWrapper() { delete udt1; }
    EnvelopeGenerator::VCA* udt1 = nullptr;
};
*/
/*
// Wrapper definitions
struct EnvelopeGeneratorWrapper
{
    EnvelopeGeneratorWrapper(EnvelopeGenerator* _udt) : udt1(_udt) { }
    ~EnvelopeGeneratorWrapper() { delete udt1; }
    EnvelopeGenerator* udt1 = nullptr;
};

struct LowFreqOscillatorWrapper
{
    LowFreqOscillatorWrapper(LowFreqOscillator* _udt) : udt1(_udt) { }
    ~LowFreqOscillatorWrapper() { delete udt1; }
    LowFreqOscillator* udt1 = nullptr;
};

struct VoiceWrapper
{
    VoiceWrapper(Voice* _udt) : udt1(_udt) { }
    ~VoiceWrapper() { delete udt1; }
    Voice* udt1 = nullptr;
};

struct SynthMoogWrapper
{
    SynthMoogWrapper(SynthMoog* _udt) : udt1(_udt) { }
    ~SynthMoogWrapper() { delete udt1; }
    SynthMoog* udt1 = nullptr;
};

struct KeithEmersonWrapper
{
    KeithEmersonWrapper(KeithEmerson* _udt) : udt1(_udt) { }
    ~KeithEmersonWrapper() { delete udt1; }
    KeithEmerson* udt1 = nullptr;
};
*/

