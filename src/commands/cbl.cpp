#include "cbl.h"

CBL::CBL() : FCommand(std::string("BRO"))
{
    setSendReceive(true, false);
}

CBL::CBL(std::string channel) : CBL()
{
    this->setChannel(channel);
}

void CBL::setChannel(std::string channel)
{
    this->parameters["channel"] = channel;
}

std::string CBL::getChannel()
{
    return this->parameters["channel"].asString();
}
