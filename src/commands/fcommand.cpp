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
