#include "fmessenger.h"

FMessenger::FMessenger(bool debug, bool secure, QObject *parent) : QObject(parent)
{
    QString url;

    if(debug && secure)
        url = SERVER_URL_TLS_DEBUG;
    else if(debug && !secure)
        url = SERVER_URL_DEBUG;
    else if(!debug && secure)
        url = SERVER_URL_TLS;
    else
        url = SERVER_URL;

    this->client = new FClient(QUrl(url),this);

    connect(this->client,SIGNAL(connected()),this,SIGNAL(connected()));
    connect(this->client,SIGNAL(disconnected()),this,SIGNAL(disconnected()));
    connect(this->client,SIGNAL(messageReceived(QString)),this,SIGNAL(commandReceived(QString)));
    connect(this->client,SIGNAL(messageSent(QString)),this,SIGNAL(commandSent(QString)));

    connect(this->client,SIGNAL(messageReceived(QString)),this,SLOT(parseCommand(QString)));
}

void FMessenger::start()
{
    this->client->open();
}

void FMessenger::stop()
{
    this->client->close();
}

void FMessenger::login(LoginTicket t)
{
    FCommand* command = new IDN(t.account,t.ticket,t.selectedCharacter);
    this->client->sendCommand(command);
}

void FMessenger::parseCommand(QString command)
{
    std::string id = FCommand::parseID(command.toStdString());

    if(id == "PIN")
        sendPing();
}

void FMessenger::sendPing()
{
    this->client->sendMessage("PIN");
}
