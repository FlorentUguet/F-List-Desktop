#ifndef FCOMMAND_H
#define FCOMMAND_H

#include <iostream>
#include "utils/jsonutils.h"

/*
enum FID{
    ACB = 0,
    AOP,
    AWC,
    BRO,
    CBL,
    CBU,
    CCR,
    CDS,
    CHA,
    CIU,
    CKU,
    COA,
    COL,
    COR,
    CRC,
    CSO,
    CTU,
    CUB,
    DOP,
    FKS,
    IDN,
    IGN,
    JCH,
    KIC,
    KIK,
    KIN,
    LCH,
    LRP,
    MSG,
    ORS,
    PIN,
    PRI,
    PRO,
    RLL,
    RLD,
    RMO,
    RST,
    RWD,
    SFC,
    STA,
    TMO,
    TPN,
    UNB,
    UPT,
    ADL,
    CON,
    ERR,
    FLN,
    HLO,
    ICH,
    KID,
    LIS,
    NLN,
    FRL,
    PRD,
    RTB,
    SYS,
    VAR
};
*/


class FCommand
{
public:
    FCommand(std::string id);
    FCommand(std::string id, Json::Value parameters);

    std::string toString();

    static std::string parseID(std::string command);
    static Json::Value parseParameters(std::string command);

protected:
    void setSendReceive(bool sendable, bool receivable);

    std::string id;
    Json::Value parameters;

    bool isReceivable; //Server Command
    bool isSendable; //Client Command
};

#endif // FCOMMAND_H
