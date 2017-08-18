#include "floginclient.h"

FLoginClient::FLoginClient(QObject *parent) : QObject(parent)
{
    this->nam = new QNetworkAccessManager(this);
    connect(nam,SIGNAL(finished(QNetworkReply*)),this,SLOT(onLoginCompleted(QNetworkReply*)));
}

void FLoginClient::login(const QString user, const QString pass)
{
    QUrlQuery postData;
    postData.addQueryItem("secure", "yes");
    postData.addQueryItem("account", user);
    postData.addQueryItem("password", pass);


    QNetworkRequest req(QUrl(QString(LOGIN_URL)));
    req.setHeader(QNetworkRequest::ContentTypeHeader,"application/x-www-form-urlencoded");

    this->nam->post(req, postData.toString(QUrl::FullyEncoded).toUtf8());
}

void FLoginClient::handleSslErrors(QList<QSslError> sslErrors)
{
    QString errorString;
    foreach(const QSslError &error, sslErrors)
    {
        if(!errorString.isEmpty())
        {
            errorString += ", ";
        }
        errorString += error.errorString();
    }
    emit error(errorString);
}

void FLoginClient::onLoginCompleted(QNetworkReply *reply)
{
    if(reply->error() != QNetworkReply::NoError)
    {
        QString errorString = "Error while login : ";
        errorString.append(reply->errorString());
        emit error(errorString);
        return;
    }

    QString response = QString::fromLocal8Bit(reply->readAll());

    bool ok;
    Json::Value root = JsonUtils::stringToJson(response.toStdString(), &ok);

    if(!ok)
    {
        emit error(QString("Internal error while parsing the response. Please contact the developper."));
    }
    else if(root.isMember("error") && (root["error"].asString() != ""))
    {
        //There's an error
        emit error(QString(root["error"].asCString()));
    }
    else
    {
        LoginTicket t(root);
        t.text = response.toStdString();

        emit loginSuccessful(response);
        emit loginSuccessful(t);
    }
}
