#ifndef FMESSENGER_H
#define FMESSENGER_H

#include <QObject>
#include <QHash>

#include "fclient.h"
#include "floginclient.h"

class FMessenger : public QObject
{
    Q_OBJECT
public:
    FMessenger(bool debug, bool secure, QObject *parent = nullptr);

signals:
    void connected();
    void disconnected();

    void commandSent(QString command);
    void commandReceived(QString command);

public slots:
    void parseCommand(QString command);
    void sendPing();

    void start();
    void stop();
    void login(LoginTicket t);

private:
    FClient *client;
    QHash<QString, QVariant> variables;
};

#endif // FMESSENGER_H
