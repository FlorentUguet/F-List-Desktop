#ifndef FCOMMAND_H
#define FCOMMAND_H

#include <iostream>
#include "utils/jsonutils.h"


class FCommand
{
public:
    FCommand(std::string id);

    std::string toString();

protected:
    void setSendReceive(bool sendable, bool receivable);

    std::string id;
    Json::Value parameters;

    bool isReceivable; //Server Command
    bool isSendable; //Client Command
};

#endif // FCOMMAND_H
