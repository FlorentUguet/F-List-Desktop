#ifndef FLOGINWIDGET_H
#define FLOGINWIDGET_H

#include <QtWidgets>
#include "controller/floginclient.h"

class FLoginWidget : public QWidget
{
    Q_OBJECT
public:
    FLoginWidget(QWidget *parent = nullptr);

signals:
    void loginSuccess(LoginTicket value);

public slots:
    void login();
    void onLoginError(QString error);
    void onLoginSuccess(LoginTicket value);
    void onLoginSuccess(QString string);

private:
    void login(const QString user, const QString pass);

    QLineEdit *leAccount;
    QLineEdit *lePassword;
    QPushButton *pbLogin;

    FLoginClient *client;
};

#endif // FLOGINWIDGET_H
