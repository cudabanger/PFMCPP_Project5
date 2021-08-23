/*
 Project 5: Part 4 / 4
 video: Chapter 3 Part 7

 Create a branch named Part4
 
 Don't #include what you don't use
 
 1) Your task is to refactor your Chapter 3 Part 4 task into separate source and header files.
         Add files via the pane on the left.
 
 2) Put all of your declarations for each class in .h files
         One header file per class ( i.e. Raider.h for a class named "Raider" )
 
 3) Put all of your implementations in .cpp files.
         one cpp file per class ( i.e. Raider.cpp for a class named "Raider" )
 
 4) Put all of your Wrapper classes in a single Wrappers.h file
         if you implemented your wrapper class functions in-class, you'll need to move them to Wrappers.cpp
 
 5) NO IN-CLASS IMPLEMENTATION ALLOWED.
         the only exception is the existing Atomic.h and LeakedObjectDetector.h
 
 6) for every .cpp file you have to make, insert it into the .replit file after 'main.cpp'.  Don't forget the spaces between file names.
 If you need help with this step, send me a DM.
 
 7) click the [run] button.  Clear up any errors or warnings as best you can.
 
 Remember, your Chapter 3 Part 4 task worked when it was all in one file. so you shouldn't need to edit any of it.  
         just split it up into source files and provide the appropriate #include directives.
 */

#include "LeakedObjectDetector.h"
#include "EnvelopeGenerator.h"
#include "LowFreqOscillator.h"
#include "Voice.h"
#include "SynthMoog.h"
#include "KeithEmerson.h"
#include "Wrappers.h"

/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.
 send me a DM to review your pull request when the project is ready for review.
 Wait for my code review.
 */
#include <iostream>
int main()
{
    // instantiate 2 each of the 5 required UDTs
    EnvelopeGeneratorWrapper envGen1( new EnvelopeGenerator() ), envGen2( new EnvelopeGenerator() );
    envGen1.udt1->setADSR(10,20,30,40);
    envGen2.udt1->setADSR(10,20,30,40);
    std::cout << "envGen1's Attack is: " << envGen1.udt1->attack << std::endl;
    envGen1.udt1->printAttackMsg();
    std::cout << "envGen2's Attack is: " << envGen2.udt1->attack << std::endl;
    envGen2.udt1->printAttackMsg();

    LowFreqOscillatorWrapper lfo1( new LowFreqOscillator() ), lfo2( new LowFreqOscillator() );
    lfo1.udt1->setParams(880, 1, 5);
    lfo2.udt1->setParams(440, 2, 35);
    std::cout << "lfo1's Frequency is: " << lfo1.udt1->frequency << std::endl;
    lfo1.udt1->printFrequencyMsg();
    std::cout << "lof2's Mod Depth is: " << lfo2.udt1->modDepth << std::endl;
    lfo2.udt1->printModDepthMsg();

    VoiceWrapper voice1( new Voice() ), voice2( new Voice() );
    std::cout << "Voice 1's Oscillator 1 attack is: " << voice1.udt1->oscWrapper1.udt1->ADSR.attack << std::endl;
    voice1.udt1->printFrequencyMsg();
    std::cout << "Voice 2's Oscillator 1 frequency is: " << voice2.udt1->oscWrapper1.udt1->frequency << std::endl;
    voice2.udt1->printAttackMsg();

    SynthMoogWrapper synth1( new SynthMoog() ), synth2( new SynthMoog() );
    synth1.udt1->setLFO(30, 1, 10);
    synth2.udt1->setLFO(60, 2, 20);
    std::cout << "Synth 1's LFO frequency is: " << synth1.udt1->lfo.frequency << std::endl;
    synth1.udt1->printLFOFrequency();
    std::cout << "Synth 2's LFO frequency is: " << synth2.udt1->lfo.frequency << std::endl;
    synth2.udt1->printLFOFrequency();

    KeithEmersonWrapper keith1( new KeithEmerson() ), keith2( new KeithEmerson() );
    keith1.udt1->activateKeyboardGodMode();
    std::cout << "Kieth 1's synth is an " << keith1.udt1->keyboards[0].getModelName() << std::endl;
    keith1.udt1->printModelName();
    keith2.udt1->activateKeyboardGodMode();
    std::cout << "Kieth 2's synth is an " << keith2.udt1->keyboards[0].getModelName() << std::endl;
    keith2.udt1->printModelName();

    std::cout << "good to go!" << std::endl;
}
