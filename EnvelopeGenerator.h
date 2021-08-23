#pragma once

#include "LeakedObjectDetector.h"

/*
 UDT 1:  With Nested UDT 1 of 2
 */
struct EnvelopeGenerator
{
    int attack, decay, sustain, release;
    bool inSignalPath { false } ;

    EnvelopeGenerator();
    ~EnvelopeGenerator();

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

    // Leaving this wrapper defined here (and removed from Wrappers.h) causes 
    // the rest of the code to work.
    /**/      
    
    //VCAWrapper vcaWrapper{ new VCA };
    //struct VCAWrapper;
    VCA vca;
};

