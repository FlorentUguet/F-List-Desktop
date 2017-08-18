#include "bro.h"

BRO::BRO() : FCommand(std::string("BRO"))
{
    setSendReceive(true, false);
}

BRO::BRO(std::string message) : BRO()
{
    this->setMessage(message);
}

void BRO::setMessage(std::string message)
{
    this->parameters["message"] = message;
}

std::string BRO::getMessage()
{
    return this->parameters["message"].asString();
}
