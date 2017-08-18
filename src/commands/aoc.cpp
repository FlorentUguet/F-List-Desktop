#include "aoc.h"

AOC::AOC() : FCommand(std::string("AOC"))
{
    setSendReceive(true, false);
}

AOC::AOC(std::string character) : AOC()
{
    this->setCharacter(character);
}

void AOC::setCharacter(std::string character)
{
    this->parameters["character"] = character;
}

std::string AOC::getCharacter()
{
    return this->parameters["character"].asString();
}
