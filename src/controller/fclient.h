#ifndef FCLIENT_H
#define FCLIENT_H

#define SERVER_URL "ws://chat.f-list.net:9722"
#define SERVER_URL_TLS "ws://chat.f-list.net:9799"
#define SERVER_URL_DEBUG "ws://chat.f-list.net:8722"
#define SERVER_URL_TLS_DEBUG  "ws://chat.f-list.net:8799"

#include <QObject>
#include <QtWebSockets/QWebSocket>

class FClient : public QObject
{
    Q_OBJECT
public:
    FClient(const QUrl url, QObject *parent = nullptr);

signals:
    void messageReceived(QString message);

public slots:
    void onError(QAbstractSocket::SocketError error);
    void onConnected();
    void onDisconnected();
    void onTextMessageReceived(QString message);
    void sendMessage(QString message);

    void open();
    void open(QUrl url);

    void close();

private:
    QWebSocket *socket = 0;
    QUrl url;
};

#endif // FCLIENT_H
