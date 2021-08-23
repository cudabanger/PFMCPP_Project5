#include "EnvelopeGenerator.h"

EnvelopeGenerator::VCA::VCA() : gain(1), leadingEdge(false), reTrigger(false) 
{
    initialize();
    gate = false;
}

EnvelopeGenerator::VCA::~VCA()
{
    //std::cout << "VCA DTOR" << std::endl;
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

EnvelopeGenerator::EnvelopeGenerator() :
attack(0),
decay(0),
sustain(0),
release(0)
{
    //std::cout << "CTOR EnvelopeGenerator" << std::endl;
    vca.initialize();
}

EnvelopeGenerator::~EnvelopeGenerator()
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
   std::cout << "envGen's Attack is: " << getAttack() << std::endl; 
}

