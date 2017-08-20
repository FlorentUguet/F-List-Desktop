#include "fclient.h"

FClient::FClient(const QUrl url, QObject *parent) : QObject(parent)
{
    this->socket = new QWebSocket(QString(),QWebSocketProtocol::VersionLatest,this);
    this->socket->ignoreSslErrors();
    this->url = url;
}

void FClient::open()
{
    connect(this->socket, SIGNAL(connected()), this, SLOT(onConnected()));
    connect(this->socket, SIGNAL(disconnected()), this, SLOT(onDisconnected()));
    connect(this->socket,SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(onError(QAbstractSocket::SocketError)));

    this->socket->open(this->url);
}

void FClient::open(QUrl url)
{
    this->url = url;
    open();
}

void FClient::close()
{
    this->socket->close();
}

void FClient::onError(QAbstractSocket::SocketError error)
{
    qDebug() << "Error " << error;
}

void FClient::onConnected()
{
    connect(this->socket,SIGNAL(textMessageReceived(QString)),this,SLOT(onTextMessageReceived(QString)));
    qDebug() << "Connected";
    emit connected();
}

void FClient::onDisconnected()
{
    qDebug() << "Disconnected";
    emit disconnected();
}

void FClient::onTextMessageReceived(QString message)
{
    emit messageReceived(message);
}

void FClient::sendMessage(QString message)
{
    this->socket->sendTextMessage(message);
    emit messageSent(message);
}

void FClient::sendCommand(FCommand *command)
{
    this->sendMessage(QString(command->toString().c_str()));
}

