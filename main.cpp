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






#include <array>
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
        ~VCA() { FIXME: add some std::cout statements to this destructor }

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
        VCAWrapper(VCA* _udt) : udt1(_udt) { }
        ~VCAWrapper() { delete udt1; }
        VCA* udt1 = nullptr;
    };

    VCAWrapper vcaWrapper{ new VCA };
};

EnvelopeGenerator::VCA::VCA() : gain(1), leadingEdge(false), reTrigger(false) 
{
    initialize();
    gate = false;
}

void EnvelopeGenerator::VCA::initialize()
{
    for (int j{ 0 }; j < 10; ++j)
    {  
        gain = j;  
    }
    fuzzy = false;
    gate = false;
}

void EnvelopeGenerator::VCA::trigger()
{
    gain = 25;
}

void EnvelopeGenerator::VCA::silence()
{
    gain = 0;
}

EnvelopeGenerator::EnvelopeGenerator() : attack(0), decay(0), sustain(0), release(0)
{
    vcaWrapper.udt1->initialize();
}

void EnvelopeGenerator::setADSR(int a, int d, int s, int r)
{
    attack = a;
    decay = d;
    sustain = s;
    release = r;

    for (int c{0}; c < 10; ++c)
        sustain = c;
}

void EnvelopeGenerator::connect(bool inPath)
{
    inSignalPath = inPath;
}

void EnvelopeGenerator::reset()
{
    attack = decay = sustain = release = 0;
}

int EnvelopeGenerator::getAttack()
{
    return this->attack;
}

void EnvelopeGenerator::printAttackMsg()
{
   std::cout << "envGen's Attack is: " << this->getAttack() << std::endl; 
}
/*
 UDT 2:
 */
struct LowFreqOscillator
{
    double  frequency;
    int     waveform; 
    int     modDepth;
    bool    tapTempo {false};
    bool    isActive {false};

    LowFreqOscillator();

    void enable();
    void disable();
    void setParams(double frequency, int waveform, int modDepth);
    double getFrequency();
    int getModDepth(); 
    void printFrequencyMsg();
    void printModDepthMsg();

    JUCE_LEAK_DETECTOR(LowFreqOscillator)
};

LowFreqOscillator::LowFreqOscillator() : frequency(440), waveform(0), modDepth(0)
{
    for (int c{10}; c < 100; ++c)
    {   
        frequency = c;
    }

    tapTempo = false;
}

void LowFreqOscillator::enable()
{
    isActive = true;
}

void LowFreqOscillator::disable()
{
    isActive = false;
}

void LowFreqOscillator::setParams(double freq, int wave, int mod)
{
    frequency = freq;
    waveform = wave;
    modDepth = mod;
}

double LowFreqOscillator::getFrequency()
{
    return this->frequency;
}

void LowFreqOscillator::printFrequencyMsg()
{
    std::cout << "lfo's Frequency is: " << this->getFrequency() << std::endl;    
}

int LowFreqOscillator::getModDepth()
{
    return this->modDepth;
}

void LowFreqOscillator::printModDepthMsg()
{
    std::cout << "lfo's Mod Depth is: " << this->getModDepth() << std::endl;    
}
/*
 UDT 3: With Nested UDT 2 of 2
 */
struct Voice
{
    Voice();

    void initialize();
    void playSound();
    void mute();
    void printFrequencyMsg();
    void printAttackMsg();

    struct Oscillator
    {
        Oscillator();

        void setFrequency(float freq);
        float getFrequency();
        void setWaveform(int freq);
        void setOscType(int type);

        EnvelopeGenerator ADSR;
        float frequency;
        int oscType, waveform;
        bool sync;

        JUCE_LEAK_DETECTOR(Oscillator)
    };

    struct OscillatorWrapper
    {
        OscillatorWrapper(Oscillator* _udt) : udt1(_udt) { }
        ~OscillatorWrapper() { delete udt1; }
        Oscillator* udt1 = nullptr;
    };

    OscillatorWrapper oscWrapper1{ new Oscillator };
    OscillatorWrapper oscWrapper2{ new Oscillator };
    OscillatorWrapper oscWrapper3{ new Oscillator };
    OscillatorWrapper oscWrapper4{ new Oscillator };

    bool isMute; 

    JUCE_LEAK_DETECTOR(Voice)
};

Voice::Voice():isMute(true)
{
    initialize();
}

void Voice::initialize()
{
    oscWrapper1.udt1->setWaveform(1);
    oscWrapper2.udt1->setWaveform(2);
    oscWrapper3.udt1->setWaveform(1);
    oscWrapper4.udt1->setWaveform(2);
}

void Voice::playSound()
{
    // play C Maj 7
    oscWrapper1.udt1->setFrequency(130.813f);
    oscWrapper2.udt1->setFrequency(164.814f);
    oscWrapper3.udt1->setFrequency(195.998f);
    oscWrapper4.udt1->setFrequency(246.942f);
}

void Voice::mute()
{
    isMute = true;
}

Voice::Oscillator::Oscillator() : oscType(1), sync(false)
{
    for (int j{0}; j < 10; ++j)
    {  
        sync = true;  
    }
    ADSR.setADSR(0,0,0,0);
}

void Voice::Oscillator::setFrequency(float freq)
{
    frequency = freq;
}

void Voice::Oscillator::setWaveform(int wave)
{
    waveform = wave;
}

float Voice::Oscillator::getFrequency()
{
    return frequency;
}

void Voice::printAttackMsg()
{
    std::cout << "Voice's Oscillator 1 attack is: " << oscWrapper1.udt1->ADSR.getAttack() << 
    std::endl;
}

void Voice::printFrequencyMsg()
{
    std::cout << "Voice's Oscillator 1 frequency is: " << oscWrapper1.udt1->getFrequency() << std::endl;
}
/*
 new UDT 4:
 */
struct SynthMoog
{
    std::array<Voice, 4> voices;
    LowFreqOscillator lfo;
    EnvelopeGenerator envGen;

    SynthMoog();
    ~SynthMoog();

    void setVoiceFreq(unsigned int VoiceNum, float freq = 440);
    void setADSR(int attack, int decay, int sustain, int release);
    void setLFO(double frequency, int waveform, int modDepth);
    void playChord();
    std::string getModelName();

    void printLFOFrequency();

    JUCE_LEAK_DETECTOR(SynthMoog)
};


SynthMoog::SynthMoog()
{

}

SynthMoog::~SynthMoog()
{
    std::cout << "Calling DTOR - SynthMoog" << std::endl; 
}

void SynthMoog::setVoiceFreq(unsigned int voiceNum, float freq)
{
    if ( voiceNum <=3 )
    {
        voices[voiceNum].oscWrapper1.udt1->setFrequency(freq);
        voices[voiceNum].oscWrapper2.udt1->setFrequency(freq);
        voices[voiceNum].oscWrapper3.udt1->setFrequency(freq);
        voices[voiceNum].oscWrapper4.udt1->setFrequency(freq);
    }
}

void SynthMoog::setADSR(int attack, int decay, int sustain, int release)
{
    envGen.setADSR(attack, decay, sustain, release);
}

void SynthMoog::setLFO(double frequency, int waveform, int modDepth)
{
    lfo.setParams(frequency, waveform, modDepth);
}

void SynthMoog::playChord()
{
    for(auto& voice : voices)
        voice.playSound();
}

std::string SynthMoog::getModelName()
{
    return "Emerson Moog Modular";
}

void SynthMoog::printLFOFrequency()
{
    std::cout << "Synth's LFO frequency is: " << this->lfo.getFrequency() << std::endl;
}
/*
 new UDT 5:
 */
struct KeithEmerson
{
    KeithEmerson();
    ~KeithEmerson();

    std::array<SynthMoog, 15> keyboards;

    void activateKeyboardGodMode();
    SynthMoog& getKeyboard(unsigned int whichKeyboard);
    void printModelName();

    JUCE_LEAK_DETECTOR(KeithEmerson)
};

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

/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.
 send me a DM to review your pull request when the project is ready for review.
 Wait for my code review.
 */

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
