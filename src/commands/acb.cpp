#include "acb.h"

ACB::ACB() : FCommand(std::string("ACB"))
{
    setSendReceive(true, false);
}

ACB::ACB(std::string character) : ACB()
{
    this->setCharacter(character);
}

void ACB::setCharacter(std::string character)
{
    this->parameters["character"] = character;
}

std::string ACB::getCharacter()
{
    return this->parameters["character"].asString();
}
