/*
Project 5: Part 2 / 4
 video: Chapter 3 Part 1

Create a branch named Part2

 The 'this' keyword
 
 The purpose of this project part is to show you how accessing member variables of objects INSIDE member functions is very similar to accessing member variables of objects OUTSIDE of member functions, via 'this->' and via the '.' operator.
 This project part will break the D.R.Y. rule, but that is fine for the purpose of this project part.
 
 0) make sure any operators (:, <, ++, =, etc) have spaces around them so they're easy to read.
    also fix any FIXMEs.
 
 1) if you don't have any std::cout statements in main() that access member variables of your U.D.Ts
         write some.
    You can copy some from your Project3's main() if needed.
 
 2) For each std::cout statement in main() that accessed member variables of your types or printed out the results of your member function calls,
        a) write a member function that prints the same thing out, but uses the proper techniques inside the member functions to access the same member variables/functions.
        b) be explicit with your use of 'this->' in those member functions so we see how you're accessing/calling those member variables and functions *inside*
        c) call that member function after your std::cout statement in main.
        d) you should see 2 (almost) identical messages in the program output for each member function you add:
            one for the std::cout line, and one for the member function's output
 
 
 3) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 */

/*
 example:
 */
#include <iostream>
namespace Example
{
    //a User-Defined Type
    struct MyFoo
    {
        MyFoo() { std::cout << "creating MyFoo" << std::endl; }
        ~MyFoo() { std::cout << "destroying MyFoo" << std::endl; }
        
		// 2a) the member function whose function body is almost identical to the std::cout statement in main.
        void memberFunc() 
        { 
            // 2b) explicitly using 'this' inside this member function.
            std::cout << "MyFoo returnValue(): " << this->returnValue() << " and MyFoo memberVariable: " << this->memberVariable << std::endl; 
        }  
        
        int returnValue() { return 3; }
        float memberVariable = 3.14f;

        /*
        note: the example functions are implemented in-class, and the ctor/dtor show the curly braces on the same line as the function declaration.
        Do not do this.  Follow the instructions and coding style for the course.
        */
    };
    
    int main()
    {
        //an instance of the User-Defined Type named mf
        MyFoo mf;
        
        // 1) a std::cout statement that uses mf's member variables
        std::cout << "mf returnValue(): " << mf.returnValue() << " and mf memberVariable: " << mf.memberVariable << std::endl; 
        
        // 2c) calling mf's member function.  the member function's body is almost identical to the cout statement above.
        mf.memberFunc();
        return 0;
    }
}

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
    return this -> frequency;
}

int LowFreqOscillator::getModDepth()
{
    return this -> modDepth;
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
    { 
        voice.playSound();
    }
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
    SynthMoog& getKeyboard(unsigned int whichKeyboard);
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
    return this->keyboards[whichKeyboard];
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
    std::cout << "envGen1's Attack is: " << envGen1.getAttack() << std::endl;
    std::cout << "envGen2's Attack is: " << envGen2.attack << std::endl;
    std::cout << "envGen2's Attack is: " << envGen2.getAttack() << std::endl;

    LowFreqOscillator lfo1, lfo2;
    lfo1.setParams(880, 1, 5);
    lfo2.setParams(440, 2, 35);
    std::cout << "lfo1's Frequency is: " << lfo1.frequency << std::endl;
    std::cout << "lfo1's Frequency is: " << lfo1.getFrequency() << std::endl;
    std::cout << "lof2's Mod Depth is: " << lfo2.modDepth << std::endl;
    std::cout << "lof2's Mod Depth is: " << lfo2.getModDepth() << std::endl;

    Voice voice1, voice2;
    int attack = voice1.osc1.ADSR.attack;
    std::cout << "Voice 1's Oscillator 1 attack is: " << attack << 
    std::endl;
    std::cout << "Voice 1's Oscillator 1 attack is: " << voice1.osc1.ADSR.getAttack() << 
    std::endl;
    float frequency = voice2.osc1.frequency;
    std::cout << "Voice 2's Oscillator 1 frequency is: " << frequency << std::endl;
    std::cout << "Voice 2's Oscillator 1 frequency is: " << voice2.osc1.getFrequency() << std::endl;

    SynthMoog synth1, synth2;
    synth1.setLFO(30, 1, 10);
    synth2.setLFO(60, 2, 20);
    std::cout << "Synth 1's LFO frequency is: " << synth1.lfo.frequency << std::endl;
    std::cout << "Synth 1's LFO frequency is: " << synth1.lfo.getFrequency() << std::endl;
    std::cout << "Synth 2's LFO frequency is: " << synth2.lfo.frequency << std::endl;
    std::cout << "Synth 2's LFO frequency is: " << synth2.lfo.getFrequency() << std::endl;

    KeithEmerson keith1, keith2;
    keith1.activateKeyboardGodMode();
    std::cout << "Kieth 1's synth is an " << keith1.keyboards[0].getModelName() << std::endl;
    std::cout << "Kieth 1's synth is an " << keith1.getKeyboard(0).getModelName() << std::endl;

    keith2.activateKeyboardGodMode();
    std::cout << "Kieth 2's synth is an " << keith2.keyboards[0].getModelName() << std::endl;
    std::cout << "Kieth 2's synth is an " << keith2.getKeyboard(0).getModelName() << std::endl;

    std::cout << "good to go!" << std::endl;
}
