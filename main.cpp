/*
Project 5: Part 1 / 4
 video Chapter 2 - Part 12
 Create a branch named Part1
Purpose:  This project continues developing Project3.
       you will learn how to take code from existing projects and migrate only what you need to new projects
       you will learn how to write code that doesn't leak as well as how to refactor. 
=============================================
Since you didn't do Project 3:
=============================================
write 3 UDTs below that EACH have: 
        5 member variables
            the member variable names and types should be relevant to the work the UDT will perform.
            pick properties that can be represented with 'int float double bool char std::string'
        3 member functions with an arbitrary number of parameters
            give some of those parameters default values.
        constructors that initialize some of these member variables
            the remaining member variables should be initialized in-class
        for() or while() loops that modify member variables
 1) 2 of your 3 UDTs need to have a nested UDT.
    this nested UDT should fulfill the same requirements as above:
        5 member variables  
        3 member functions
        constructors and loops.
        
 2) Define your implementations of all functions OUTSIDE of the class. 
 NO IN-CLASS IMPLEMENTATION ALLOWED
 3) add destructors to all of your UDTs
        make the destructors do something like print out the name of the class.
 
 4) add 2 new UDTs that use only the types you copied above as member variables.
 
 5) Add destructors to these 2 new types that do something.  
        maybe print out the name of the class being destructed, or call a member function of one of the members.  be creative
 
 6) use at least 2 instances of each of your UDTs in main. 
        add some std::cout statements in main() that use your UDT's member variables.
 
 7) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
If you need inspiration for what to write, take a look at previously approved student projects in the Slack Workspace channel for this project part.
 */
#include <iostream>
#include <array>
/*
 UDT 1:
 */
struct EnvelopeGenerator
{
    int attack, decay, sustain, release;
    bool inSignalPath {false} ;

    EnvelopeGenerator();

    void setADSR(int attack = 0, int decay = 0, int sustain = 0, int release = 0);
    void connect(bool inSignalPath);
    void reset();
};

EnvelopeGenerator::EnvelopeGenerator() : attack(0), decay(0), sustain(0), release(0)
{

}

void EnvelopeGenerator::setADSR(int a, int d, int s, int r)
{
    attack = a;
    decay = d;
    sustain = s;
    release = r;

    for (int c{0}; c <10; c++)
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
/*
 UDT 3:
 */
struct Voice
{
    Voice();

    void initialize();
    void playSound();
    void mute();

    struct Oscillator
    {
        Oscillator();

        void setFrequency(float freq);
        void setWaveform(int freq);
        void setOscType(int type);

        EnvelopeGenerator ADSR;
        float frequency;
        int oscType, waveform;
        bool sync;
    };
    
    Oscillator osc1, osc2, osc3, osc4;
    bool isMute; 
};

Voice::Voice():isMute(true)
{
    initialize();
}

void Voice::initialize()
{
    osc1.setWaveform(1);
    osc2.setWaveform(2);
    osc3.setWaveform(1);
    osc4.setWaveform(2);
}

void Voice::playSound()
{
    // play C Maj 7
    osc1.setFrequency(130.813f);
    osc2.setFrequency(164.814f);
    osc3.setFrequency(195.998f);
    osc3.setFrequency(246.942f);
}

void Voice::mute()
{
    isMute = true;
}

Voice::Oscillator::Oscillator() : oscType(1), sync(false)
{
    for (int j{0}; j< 10; ++j)
        sync = true;

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
        voices[voiceNum].osc1.setFrequency(freq);
        voices[voiceNum].osc2.setFrequency(freq);
        voices[voiceNum].osc3.setFrequency(freq);
        voices[voiceNum].osc4.setFrequency(freq);
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
    for(auto& voice: voices)
        voice.playSound();
}

std::string SynthMoog::getModelName()
{
    return "Emerson Moog Modular";
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
        keyboard.playChord();   
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

//#include <iostream>
int main()
{
    // instantiate 2 each of the 5 required UDTs
    EnvelopeGenerator envGen1, envGen2;
    envGen1.setADSR(10,20,30,40);
    envGen2.setADSR(40,30,20,10);
    std::cout << "envGen1's Attack is: " << envGen1.attack << std::endl;
    std::cout << "envGen2's Attack is: " << envGen2.attack << std::endl;

    LowFreqOscillator lfo1, lfo2;
    lfo1.setParams(880, 1, 5);
    lfo2.setParams(440, 2, 35);
    std::cout << "lfo1's Frequency is: " << lfo1.frequency << std::endl;
    std::cout << "lof2's Mod Depth is: " << lfo2.modDepth << std::endl;

    Voice voice1, voice2;
    int attack = voice1.osc1.ADSR.attack;
    std::cout << "Voice 1's Oscillator 1 attack is: " << attack << 
    std::endl;
    float frequency = voice2.osc1.frequency;
    std::cout << "Voice 2's Oscillator 1 frequency is: " << frequency << std::endl;


    SynthMoog synth1, synth2;
    synth1.setLFO(30, 1, 10);
    synth2.setLFO(60, 2, 20);
    std::cout << "Synth 1's LFO frequency is: " << synth1.lfo.frequency << std::endl;
    std::cout << "Synth 2's LFO frequency is: " << synth2.lfo.frequency << std::endl;

    KeithEmerson keith1, keith2;
    keith1.activateKeyboardGodMode();
    std::cout << "Kieth 1's synth is an " << keith1.keyboards[0].getModelName() << std::endl;

    keith2.activateKeyboardGodMode();
    std::cout << "Kieth 2's synth is an " << keith2.keyboards[0].getModelName() << std::endl;

    std::cout << "good to go!" << std::endl;
}
