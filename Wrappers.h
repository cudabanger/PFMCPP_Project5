#pragma once

/*
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

// Wrapper definitions
struct EnvelopeGenerator;
struct EnvelopeGeneratorWrapper
{
    EnvelopeGeneratorWrapper(EnvelopeGenerator* _udt);
    ~EnvelopeGeneratorWrapper();
    EnvelopeGenerator* udt1 = nullptr;
};

struct LowFreqOscillator;
struct LowFreqOscillatorWrapper
{
    LowFreqOscillatorWrapper(LowFreqOscillator* _udt);
    ~LowFreqOscillatorWrapper();

    LowFreqOscillator* udt1 = nullptr;
};

struct Voice;
struct VoiceWrapper
{
    VoiceWrapper(Voice* _udt);
    ~VoiceWrapper();

    Voice* udt1 = nullptr;
};

struct SynthMoog;
struct SynthMoogWrapper
{
    SynthMoogWrapper(SynthMoog* _udt);
    ~SynthMoogWrapper();

    SynthMoog* udt1 = nullptr;
};

struct KeithEmerson;
struct KeithEmersonWrapper
{
    KeithEmersonWrapper(KeithEmerson* _udt);
    ~KeithEmersonWrapper();

    KeithEmerson* udt1 = nullptr;
};


