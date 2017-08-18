#ifndef CBL_H
#define CBL_H

//https://wiki.f-list.net/F-Chat_Client_Commands#BRO

#include "fcommand.h"

class CBL : public FCommand
{
public:
    CBL();
    CBL(std::string channel);

    void setChannel(std::string channel);
    std::string getChannel();

private:
};

#endif // CBL_H
