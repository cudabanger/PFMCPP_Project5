#pragma once
#include <array>
#include "LeakedObjectDetector.h"
#include"SynthMoog.h"
/*
 new UDT 5:
 */
struct KeithEmerson
{
    KeithEmerson();
    ~KeithEmerson();

    //std::array<SynthMoog, 15> keyboards;
    std::array<SynthMoog, 1> keyboards;

    void activateKeyboardGodMode();
    SynthMoog& getKeyboard(unsigned int whichKeyboard);
    void printModelName();

    JUCE_LEAK_DETECTOR(KeithEmerson)
};
