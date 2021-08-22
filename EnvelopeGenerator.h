#pragma once

#include "Wrappers.h"
#include "LeakedObjectDetector.h"
/*
 UDT 1:  With Nested UDT 1 of 2
 */
struct EnvelopeGenerator
{
    int attack, decay, sustain, release;
    bool inSignalPath { false } ;

    EnvelopeGenerator();

    void setADSR(int attack = 0, int decay = 0, int sustain = 0, int release = 0);
    void connect(bool inSignalPath);
    void reset();
    int getAttack();
    void printAttackMsg();

    JUCE_LEAK_DETECTOR(EnvelopeGenerator)
    
    struct VCA
    { // 5 member variables 3 member functions constructors and loops.
        VCA();
        ~VCA();

        void initialize();
        void trigger();
        void silence();

        float gain;
        bool leadingEdge;
        bool reTrigger;
        bool fuzzy;
        bool gate;

        JUCE_LEAK_DETECTOR(VCA)
    };

    struct VCAWrapper
    {
        VCAWrapper(EnvelopeGenerator::VCA* _udt) : udt1(_udt) { }
        ~VCAWrapper() { delete udt1; }
        EnvelopeGenerator::VCA* udt1 = nullptr;
    };      
    
    VCAWrapper vcaWrapper{ new VCA };
};

