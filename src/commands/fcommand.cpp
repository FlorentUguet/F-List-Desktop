#include "fcommand.h"

FCommand::FCommand(std::string id)
{
    this->id = id;
}

FCommand::FCommand(std::string id, Json::Value parameters)
{
    this->id = id;
    this->parameters = parameters;
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

std::string FCommand::parseID(std::string command)
{
    std::string ID;

    ID = command.substr(0,3);

    return ID;
}

Json::Value FCommand::parseParameters(std::string command)
{
    std::string json = command.substr(4,command.size()-4);
    return JsonUtils::stringToJson(json);
}
