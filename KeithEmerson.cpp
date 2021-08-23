#include <iostream>
#include "KeithEmerson.h"

KeithEmerson::KeithEmerson()
{

}

KeithEmerson::~KeithEmerson()
{
    std::cout << "Calling DTOR - KeithEmerson. RIP" << std::endl; 
}

void KeithEmerson::activateKeyboardGodMode()
{
    for(auto& keyboard: keyboards)
    {
        keyboard.playChord(); 
    }  
}

SynthMoog& KeithEmerson::getKeyboard(unsigned int whichKeyboard)
{
    if (whichKeyboard > 14)
        whichKeyboard = 14; // clamp if higher
    return this->keyboards[whichKeyboard];
}

void KeithEmerson::printModelName()
{
    std::cout << "Kieth's synth is an " << this->getKeyboard(0).getModelName() << std::endl;
}
