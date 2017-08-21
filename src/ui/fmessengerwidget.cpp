#include "fmessengerwidget.h"

FMessengerWidget::FMessengerWidget(QWidget *parent) : QWidget(parent)
{
    init();
}

void FMessengerWidget::init()
{
    //Backend
    this->messenger = new FMessenger(true,false,this);
    this->messenger->start();

    //UI
    this->console = new FConsoleWidget(this);

    QVBoxLayout *l = new QVBoxLayout;
    l->addWidget(this->console);
    setLayout(l);

    connect(this->messenger,SIGNAL(commandReceived(QString)),this->console,SLOT(commandReceived(QString)));
    connect(this->messenger,SIGNAL(commandSent(QString)),this->console,SLOT(commandSent(QString)));

    connect(this->messenger,SIGNAL(connected()),this,SLOT(login()));
}

void FMessengerWidget::login()
{
    loginWidget = new FLoginWidget(0);
    connect(loginWidget,SIGNAL(loginSuccess(LoginTicket)),this,SLOT(onLoginSuccessful(LoginTicket)));
    loginWidget->show();
}

void FMessengerWidget::onLoginSuccessful(LoginTicket t)
{
    delete this->loginWidget;
    this->messenger->login(t);
}
