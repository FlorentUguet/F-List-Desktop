#include "awc.h"

AWC::AWC() : FCommand(std::string("AWC"))
{
    setSendReceive(true, false);
}

AWC::AWC(std::string character) : AWC()
{
    this->setCharacter(character);
}

void AWC::setCharacter(std::string character)
{
    this->parameters["character"] = character;
}

std::string AWC::getCharacter()
{
    return this->parameters["character"].asString();
}
