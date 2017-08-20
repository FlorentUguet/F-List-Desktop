#include "idn.h"

IDN::IDN() : FCommand("IDN")
{
    setClientName(CLIENT_NAME);
    setClientVersion(CLIENT_VERSION);
    this->parameters["method"] = std::string("ticket");
}

IDN::IDN(std::string account, std::string ticket, std::string character) : FCommand("IDN")
{
    setClientName(CLIENT_NAME);
    setClientVersion(CLIENT_VERSION);
    this->parameters["method"] = std::string("ticket");

    setData(account,ticket,character);
}

void IDN::setData(std::string account, std::string ticket, std::string character)
{
    setAccount(account);
    setTicket(ticket);
    setCharacter(character);
}

void IDN::setClientName(std::string client)
{
    this->parameters["cname"] = client;
}

void IDN::setClientVersion(std::string version)
{
    this->parameters["cversion"] = version;
}

void IDN::setCharacter(std::string character)
{
    this->parameters["character"] = character;
}

void IDN::setTicket(std::string ticket)
{
    this->parameters["ticket"] = ticket;
}

void IDN::setAccount(std::string account)
{
    this->parameters["account"] = account;
}
