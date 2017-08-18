#ifndef AWC_H
#define AWC_H


//https://wiki.f-list.net/F-Chat_Client_Commands#AWC

#include "fcommand.h"

class AWC : public FCommand
{
public:
    AWC();
    AWC(std::string character);

    void setCharacter(std::string character);
    std::string getCharacter();

private:
};

#endif // AWC_H
