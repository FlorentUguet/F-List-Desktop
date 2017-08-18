#ifndef AOC_H
#define AOC_H


//https://wiki.f-list.net/F-Chat_Client_Commands#AOC

#include "fcommand.h"

class AOC : public FCommand
{
public:
    AOC();
    AOC(std::string character);

    void setCharacter(std::string character);
    std::string getCharacter();

private:
};

#endif // AOC_H
