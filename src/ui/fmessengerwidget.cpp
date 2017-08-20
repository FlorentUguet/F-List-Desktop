#include "fmessengerwidget.h"

FMessengerWidget::FMessengerWidget(QWidget *parent) : QWidget(parent)
{
    init();
}

void FMessengerWidget::init()
{
    //Backend
    this->client = new FClient(QUrl(SERVER_URL_DEBUG), this);
    this->client->open();

    //UI
    this->console = new FConsoleWidget(this);

    QVBoxLayout *l = new QVBoxLayout;
    l->addWidget(this->console);
    setLayout(l);

    connect(this->client,SIGNAL(messageReceived(QString)),this->console,SLOT(commandReceived(QString)));
    connect(this->client,SIGNAL(messageSent(QString)),this->console,SLOT(commandSent(QString)));

    connect(this->client,SIGNAL(connected()),this,SLOT(login()));
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

    IDN* command = new IDN(t.account,t.ticket,t.selectedCharacter);

    client->sendCommand(command);
}
