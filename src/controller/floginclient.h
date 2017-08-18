#ifndef FLOGINCLIENT_H
#define FLOGINCLIENT_H

//OpenSSL
//http://slproweb.com/products/Win32OpenSSL.html
//https://indy.fulgan.com/SSL/

//API Ticket
//https://www.f-list.net/json/getApiTicket.json

#define LOGIN_URL "https://www.f-list.net/json/getApiTicket.json"

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QUrlQuery>

#include "utils/jsonutils.h"

#include <vector>
#include <string>

struct LoginTicket
{
    std::vector<std::string> characters;
    std::string defaultCharacter;
    std::string ticket;
    std::vector< std::vector<std::string> > friends;
    std::vector<std::string> bookmarks;
    Json::Value root;
    std::string text;

    LoginTicket(Json::Value root)
    {
        //Characters
        for(int i=0;i<root["characters"].size();i++)
        {
            std::string character = root["characters"][i].asString();
            characters.push_back(root["characters"][i].asString());

            friends.push_back(std::vector<std::string>());

            for(int j=0;j<root["friends"].size();j++)
                if(root["friends"][j]["dest_name"] == character)
                    friends[i].push_back(root["friends"][j]["source_name"].asString());
        }


        //Default Character
        defaultCharacter = root["default_character"].asString();

        //Ticket
        ticket = root["ticket"].asString();

        //Bookmarks
        for(int i=0;i<root["bookmarks"].size();i++)
        {
            bookmarks.push_back(root["bookmarks"][i]["name"].asString());
        }

    }
};


class FLoginClient : public QObject
{
    Q_OBJECT
public:
    FLoginClient(QObject *parent = nullptr);

    void login(const QString user, const QString pass);

signals:
    void error(QString message);
    void loginSuccessful(LoginTicket data);
    void loginSuccessful(QString data);

public slots:
    void onLoginCompleted(QNetworkReply *reply);
    void handleSslErrors(QList<QSslError> sslErrors);

private:
    QNetworkAccessManager *nam;
};

#endif // FLOGINCLIENT_H
