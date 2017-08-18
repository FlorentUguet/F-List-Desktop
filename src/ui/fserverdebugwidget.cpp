#include "fserverdebugwidget.h"

FServerDebugWidget::FServerDebugWidget(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout;
    QHBoxLayout *layoutButtons = new QHBoxLayout;

    browser = new QTextBrowser(this);
    lineEdit = new QLineEdit(this);

    QPushButton *pbSend = new QPushButton("Send", this);
    QPushButton *pbConnect = new QPushButton("Connect", this);
    QPushButton *pbDisconnect = new QPushButton("Disconnect", this);

    layoutButtons->addWidget(pbConnect);
    layoutButtons->addWidget(pbDisconnect);
    layoutButtons->addWidget(pbSend);

    layout->addWidget(browser);
    layout->addWidget(lineEdit);
    layout->addLayout(layoutButtons);

    setLayout(layout);

    this->client = new FClient(QUrl(QString(SERVER_URL_DEBUG)),this);

    connect(pbSend,SIGNAL(clicked(bool)),this,SLOT(sendMessage()));
    connect(pbConnect,SIGNAL(clicked(bool)),this->client,SLOT(open()));
    connect(pbDisconnect,SIGNAL(clicked(bool)),this->client,SLOT(close()));
}

void FServerDebugWidget::sendMessage()
{
    emit sendMessage(lineEdit->text());
    lineEdit->clear();
}

void FServerDebugWidget::messageReceived(QString message)
{
    this->browser->setText(this->browser->toPlainText() + QString('\n') + message);
}
