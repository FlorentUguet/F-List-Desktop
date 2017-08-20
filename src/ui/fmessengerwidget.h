#ifndef FMESSENGER_H
#define FMESSENGER_H

#include <QtWidgets>

#include "floginwidget.h"
#include "fconsolewidget.h"

#include "controller/fclient.h"

class FMessengerWidget : public QWidget
{
    Q_OBJECT
public:
    FMessengerWidget(QWidget *parent = nullptr);
    void init();

signals:

public slots:
    void login();
    void onLoginSuccessful(LoginTicket t);

private:
    FClient *client;
    FLoginWidget *loginWidget;

    //Widgets
    FConsoleWidget *console;
};

#endif // FMESSENGER_H
