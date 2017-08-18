#ifndef ACB_H
#define ACB_H

//https://wiki.f-list.net/F-Chat_Client_Commands#ACB

#include "fcommand.h"

class ACB : public FCommand
{
public:
    ACB();
    ACB(std::string character);

    void setCharacter(std::string character);
    std::string getCharacter();

private:
};

#endif // ACB_H
