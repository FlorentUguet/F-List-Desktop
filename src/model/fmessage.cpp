#include "fmessage.h"

FMessage::FMessage(FCharacter *sender, std::string message)
{
    this->sender = sender;
    this->message = message;
}
