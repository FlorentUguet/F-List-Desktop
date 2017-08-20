#ifndef IDN_H
#define IDN_H

//https://wiki.f-list.net/F-Chat_Client_Commands#IDN

#include "fcommand.h"
#include "defines.h"

class IDN : public FCommand
{
public:
    IDN();
    IDN(std::string account, std::string ticket, std::string character);

    void setData(std::string account, std::string ticket, std::string character);
    void setClientName(std::string client);
    void setClientVersion(std::string version);
    void setCharacter(std::string character);
    void setTicket(std::string ticket);
    void setAccount(std::string account);

};

#endif // IDN_H
