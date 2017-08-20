#ifndef FMESSAGE_H
#define FMESSAGE_H

#include <iostream>
#include "fcharacter.h"

class FMessage
{
public:
    FMessage(FCharacter *sender, std::string message);

private:
    FCharacter *sender;
    std::string message;
};

#endif // FMESSAGE_H
