#include "fcommand.h"

FCommand::FCommand(std::string id)
{
    this->id = id;
}

void FCommand::setSendReceive(bool sendable, bool receivable)
{
    this->isReceivable = receivable;
    this->isSendable = sendable;
}

std::string FCommand::toString()
{
    std::string id = this->id + " ";

    Json::FastWriter writer;
    std::string json = writer.write(this->parameters);

    return (id + json);
}
