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
    int defaultCharacterIndex;

    std::string account;
    std::string ticket;
    std::vector<std::vector<std::string>> friends;
    std::vector<std::string> bookmarks;

    std::string selectedCharacter;

    LoginTicket(Json::Value root)
    {
        //Characters
        for(unsigned i=0;i<root["characters"].size();i++)
        {
            std::string character = root["characters"][i].asString();
            characters.push_back(character);

            friends.push_back(std::vector<std::string>());

            for(unsigned int j=0;j<root["friends"].size();j++)
                if(root["friends"][j]["dest_name"] == character)
                    friends[i].push_back(root["friends"][j]["source_name"].asString());
        }

        defaultCharacterIndex = 0;

        for(unsigned i=0; i<characters.size();i++)
        {
            if(characters[i] == defaultCharacter)
            {
                defaultCharacterIndex = i;
                break;
            }
        }


        //Default Character
        defaultCharacter = root["default_character"].asString();

        //Ticket
        ticket = root["ticket"].asString();

        //Bookmarks
        for(unsigned i=0;i<root["bookmarks"].size();i++)
            bookmarks.push_back(root["bookmarks"][i]["name"].asString());
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
    QString account;
};

#endif // FLOGINCLIENT_H
