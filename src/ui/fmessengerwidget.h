#ifndef FMESSENGERWIDGET_H
#define FMESSENGERWIDGET_H

#include <QtWidgets>

#include "floginwidget.h"
#include "fconsolewidget.h"

#include "controller/fmessenger.h"
#include "commands/commands.h"

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
    FMessenger *messenger;
    FLoginWidget *loginWidget;

    //Widgets
    FConsoleWidget *console;
};

#endif // FMESSENGERWIDGET_H
