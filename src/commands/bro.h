#ifndef BRO_H
#define BRO_H

//https://wiki.f-list.net/F-Chat_Client_Commands#BRO

#include "fcommand.h"

class BRO : public FCommand
{
public:
    BRO();
    BRO(std::string message);

    void setMessage(std::string message);
    std::string getMessage();

private:
};


#endif // BRO_H
