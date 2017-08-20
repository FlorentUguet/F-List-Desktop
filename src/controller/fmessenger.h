#ifndef FMESSENGER_H
#define FMESSENGER_H

#include <QObject>
#include <QHash>

#include "fclient.h"

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

private:
    void process(QString command);

    FClient *client;
    QHash variables;
};

#endif // FMESSENGER_H
