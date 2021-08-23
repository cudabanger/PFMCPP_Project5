#pragma once

#include "EnvelopeGenerator.h"  // Cant forward declare the nested UDT, ok for everything else

// Wrapper definitions
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

struct VCAWrapper
{
    EnvelopeGenerator::VCA* udt1 = nullptr;

    VCAWrapper(EnvelopeGenerator::VCA* _udt);
    ~VCAWrapper();
};


