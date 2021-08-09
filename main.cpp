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
/*
 UDT 1:
 */
class EnvelopeGenerator
{
public:
    int m_attack, m_decay, m_sustain, m_release;
    bool m_inSignalPath {false} ;

    EnvelopeGenerator();

    void setADSR(int attack = 0, int decay = 0, int sustain = 0, int release = 0);
    void connect(bool inSignalPath);
    void reset();
};

EnvelopeGenerator::EnvelopeGenerator():m_attack(0), m_decay(0), m_sustain(0), m_release(0)
{

}

void EnvelopeGenerator::setADSR(int attack, int decay, int sustain, int release)
{
    m_attack = attack;
    m_decay = decay;
    m_sustain = sustain;
    m_release = release;

    for (int c= 0; c <10; c++)
        m_sustain = c;
}

void EnvelopeGenerator::connect(bool inSignalPath)
{
    m_inSignalPath = inSignalPath;
}

void EnvelopeGenerator::reset()
{
    m_attack = m_decay = m_sustain = m_release = 0;
}
/*
 UDT 2:
 */
class LowFreqOscillator
{
public:
    double  m_frequency;
    int     m_waveform; 
    int     m_modDepth;
    bool    m_tapTempo {false};
    bool    m_isActive {false};

    LowFreqOscillator();

    void enable();
    void disable();
    void setParams(double frequency, int waveform, int modDepth); 
};

LowFreqOscillator::LowFreqOscillator():m_frequency(440),m_waveform(0), m_modDepth(0)
{
    for (int c = 10; c < 100; ++c)
    {   
        m_frequency = c;
    }

    m_tapTempo = false;
}

void LowFreqOscillator::enable()
{
    m_isActive = true;
}

void LowFreqOscillator::disable()
{
    m_isActive = false;
}

void LowFreqOscillator::setParams(double frequency, int waveform, int modDepth)
{
    m_frequency = frequency;
    m_waveform = waveform;
    m_modDepth = modDepth;
}
/*
 UDT 3:
 */
class Voice
{
public:
    Voice();

    void initialize();
    void playSound();
    void mute();

    class Oscillator
    {
    public:
        Oscillator();

        void setFrequency(float freq);
        void setWaveform(int freq);
        void setOscType(int type);

        EnvelopeGenerator m_ADSR;
        float m_frequency;
        int m_oscType, m_waveform;
        bool m_sync;
    };
    
    Oscillator m_Osc1, m_Osc2, m_Osc3, m_Osc4;
    bool m_mute {true};
};

Voice::Voice():m_mute(true)
{
    initialize();
}

void Voice::initialize()
{
    m_Osc1.setWaveform(1);
    m_Osc2.setWaveform(2);
    m_Osc3.setWaveform(1);
    m_Osc4.setWaveform(2);
}

void Voice::playSound()
{
    // play C Maj 7
    m_Osc1.setFrequency(130.813f);
    m_Osc2.setFrequency(164.814f);
    m_Osc3.setFrequency(195.998f);
    m_Osc3.setFrequency(246.942f);
}

void Voice::mute()
{
    m_mute = true;
}

Voice::Oscillator::Oscillator():m_oscType(1),m_sync(false)
{
    for (int j = 0; j< 10; j++)
        m_sync = true;

    m_ADSR.setADSR(0,0,0,0);
}

void Voice::Oscillator::setFrequency(float freq)
{
    m_frequency = freq;
}

void Voice::Oscillator::setWaveform(int waveform)
{
    m_waveform = waveform;
}
/*
 new UDT 4:
 */
class synthMoog
{
public:
    Voice m_Voice[4];
    LowFreqOscillator m_LFO;
    EnvelopeGenerator m_envGen;

    synthMoog();
    ~synthMoog();

    void setVoiceFreq(int VoiceNum, float freq = 440);
    void setADSR(int attack, int decay, int sustain, int release);
    void setLFO(double frequency, int waveform, int modDepth);
    void playChord();
    std::string getModelName();
};


synthMoog::synthMoog()
{

}

synthMoog::~synthMoog()
{
    std::cout << "Calling DTOR - synthMoog" << std::endl; 
}

void synthMoog::setVoiceFreq(int voiceNum, float freq)
{
    for (int c = 0; c < 4; c++)
    {
        m_Voice[voiceNum].m_Osc1.setFrequency(freq);
        m_Voice[voiceNum].m_Osc2.setFrequency(freq);
        m_Voice[voiceNum].m_Osc3.setFrequency(freq);
        m_Voice[voiceNum].m_Osc4.setFrequency(freq);
    }
}

void synthMoog::setADSR(int attack, int decay, int sustain, int release)
{
    m_envGen.setADSR(attack, decay, sustain, release);
}

void synthMoog::setLFO(double frequency, int waveform, int modDepth)
{
    m_LFO.setParams(frequency, waveform, modDepth);
}

void synthMoog::playChord()
{
    for (int voiceNum = 0; voiceNum < 4; voiceNum++)
    {
        m_Voice[voiceNum].playSound();
        m_Voice[voiceNum].playSound();
        m_Voice[voiceNum].playSound();
        m_Voice[voiceNum].playSound();
    }
}

std::string synthMoog::getModelName()
{
    return "Emerson Moog Modular";
}
/*
 new UDT 5:
 */
class keithEmerson
{
public:
    keithEmerson();
    ~keithEmerson();

    synthMoog m_keyboards[15];

    void activateKeyboardGodMode();
};

keithEmerson::keithEmerson()
{

}

keithEmerson::~keithEmerson()
{
    std::cout << "Calling DTOR - keithEmerson. RIP" << std::endl; 
}

void keithEmerson::activateKeyboardGodMode()
{
    for (int c = 0; c < 15; c++)
        m_keyboards[c].playChord();
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
    std::cout << "envGen1's Attack is: " << envGen1.m_attack << std::endl;
    std::cout << "envGen2's Attack is: " << envGen2.m_attack << std::endl;

    LowFreqOscillator lfo1, lfo2;
    lfo1.setParams(880, 1, 5);
    lfo2.setParams(440, 2, 35);
    std::cout << "lfo1's Frequency is: " << lfo1.m_frequency << std::endl;
    std::cout << "lof2's Mod Depth is: " << lfo2.m_modDepth << std::endl;

    Voice voice1, voice2;
    int attack = voice1.m_Osc1.m_ADSR.m_attack;
    std::cout << "Voice 1's Oscillator 1 attack is: " << attack << 
    std::endl;
    float frequency = voice2.m_Osc1.m_frequency;
    std::cout << "Voice 2's Oscillator 1 frequency is: " << frequency << std::endl;


    synthMoog synth1, synth2;
    synth1.setLFO(30, 1, 10);
    synth2.setLFO(60, 2, 20);
    std::cout << "Synth 1's LFO frequency is: " << synth1.m_LFO.m_frequency << std::endl;
    std::cout << "Synth 2's LFO frequency is: " << synth2.m_LFO.m_frequency << std::endl;

    keithEmerson keith1, keith2;
    keith1.activateKeyboardGodMode();
    std::cout << "Kieth 1's synth is an " << keith1.m_keyboards[0].getModelName() << std::endl;

    keith2.activateKeyboardGodMode();
    std::cout << "Kieth 2's synth is an " << keith2.m_keyboards[0].getModelName() << std::endl;

    std::cout << "good to go!" << std::endl;
}
