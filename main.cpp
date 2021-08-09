/*
 Project 5: Part 3 / 4
 video: Chapter 3 Part 4: 

Create a branch named Part3

 the 'new' keyword

 1) add #include "LeakedObjectDetector.h" to main
 
 2) Add 'JUCE_LEAK_DETECTOR(OwnerClass)' at the end of your UDTs.
 
 3) write the name of your class where it says "OwnerClass"
 
 4) write wrapper classes for each type similar to how it was shown in the video
 
 5) update main() 
      replace your objects with your wrapper classes, which have your UDTs as pointer member variables.
      
    This means if you had something like the following in your main() previously: 
*/
#if false
 Axe axe;
 std::cout << "axe sharpness: " << axe.sharpness << "\n";
 #endif
 /*
    you would update that to use your wrappers:
    
 */

#if false
AxeWrapper axWrapper( new Axe() );
std::cout << "axe sharpness: " << axWrapper.axPtr->sharpness << "\n";
#endif
/*
notice that the object name has changed from 'axe' to 'axWrapper'
You don't have to do this, you can keep your current object name and just change its type to your Wrapper class

 8) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 see here for an example: https://repl.it/@matkatmusic/ch3p04example

 you can safely ignore any warnings about exit-time-destructors.
 if you would like to suppress them, add -Wno-exit-time-destructors to the .replit file 
   with the other warning suppression flags
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
    int getAttack();
    void printAttackMsg();
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
 UDT 3:
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
    for (int j{0}; j < 10; ++j)
    {  
        sync = true;  //FIXME:  why are you setting 'sync' to true 10 times in a row?
        // ANSWER: same reason there's a needless loop here.  Pedagogy.
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
    return this->frequency;
}

void Voice::printAttackMsg()
{
    std::cout << "Voice's Oscillator 1 attack is: " << this->osc1.ADSR.getAttack() << 
    std::endl;
}

void Voice::printFrequencyMsg()
{
    std::cout << "Voice's Oscillator 1 frequency is: " << this->osc1.getFrequency() << std::endl;
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

//#include <iostream>
int main()
{
    // instantiate 2 each of the 5 required UDTs
    EnvelopeGenerator envGen1, envGen2;
    envGen1.setADSR(10,20,30,40);
    envGen2.setADSR(40,30,20,10);
    std::cout << "envGen1's Attack is: " << envGen1.attack << std::endl;
    envGen1.printAttackMsg();

    std::cout << "envGen2's Attack is: " << envGen2.attack << std::endl;
    envGen2.printAttackMsg();

    LowFreqOscillator lfo1, lfo2;
    lfo1.setParams(880, 1, 5);
    lfo2.setParams(440, 2, 35);
    std::cout << "lfo1's Frequency is: " << lfo1.frequency << std::endl;
    lfo1.printFrequencyMsg();
    std::cout << "lof2's Mod Depth is: " << lfo2.modDepth << std::endl;
    lfo2.printModDepthMsg();

    Voice voice1, voice2;
    int attack = voice1.osc1.ADSR.attack;
    std::cout << "Voice 1's Oscillator 1 attack is: " << attack << 
    std::endl;
    voice1.printFrequencyMsg();
    float frequency = voice2.osc1.frequency;
    std::cout << "Voice 2's Oscillator 1 frequency is: " << frequency << std::endl;
    voice2.printAttackMsg();

    SynthMoog synth1, synth2;
    synth1.setLFO(30, 1, 10);
    synth2.setLFO(60, 2, 20);
    std::cout << "Synth 1's LFO frequency is: " << synth1.lfo.frequency << std::endl;
    synth1.printLFOFrequency();
    std::cout << "Synth 2's LFO frequency is: " << synth2.lfo.frequency << std::endl;
    synth2.printLFOFrequency();

    KeithEmerson keith1, keith2;
    keith1.activateKeyboardGodMode();
    std::cout << "Kieth 1's synth is an " << keith1.keyboards[0].getModelName() << std::endl;
    keith1.printModelName();

    keith2.activateKeyboardGodMode();
    std::cout << "Kieth 2's synth is an " << keith2.keyboards[0].getModelName() << std::endl;
    keith2.printModelName();

    std::cout << "good to go!" << std::endl;
}
