#include "floginwidget.h"

FLoginWidget::FLoginWidget(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout;
    QHBoxLayout *layoutButtons = new QHBoxLayout;
    QGridLayout *layoutInputs = new QGridLayout;

    this->leAccount = new QLineEdit(this);
    this->lePassword = new QLineEdit(this);

    this->lePassword->setEchoMode(QLineEdit::Password);
    this->lePassword->setInputMethodHints(Qt::ImhHiddenText| Qt::ImhNoPredictiveText|Qt::ImhNoAutoUppercase);

    pbLogin = new QPushButton("Login",this);
    QPushButton *pbExit = new QPushButton("Exit",this);

    QLabel *labelUser = new QLabel("Account :", this);
    QLabel *labelPass = new QLabel("Password :", this);

    layoutInputs->addWidget(labelUser);
    layoutInputs->addWidget(leAccount);
    layoutInputs->addWidget(labelPass);
    layoutInputs->addWidget(lePassword);

    layoutButtons->addWidget(pbLogin);
    layoutButtons->addWidget(pbExit);

    layout->addLayout(layoutInputs);
    layout->addLayout(layoutButtons);
    setLayout(layout);

    //Client
    this->client = new FLoginClient(this);

    connect(this->client,SIGNAL(error(QString)),this,SLOT(onLoginError(QString)));
    //connect(this->client,SIGNAL(loginSuccessful(QString)),this,SLOT(onLoginSuccess(QString)));
    connect(this->client,SIGNAL(loginSuccessful(LoginTicket)),this,SLOT(onLoginSuccess(LoginTicket)));

    connect(pbExit,SIGNAL(clicked(bool)),qApp,SLOT(quit()));

    connect(lePassword,SIGNAL(returnPressed()),this,SLOT(login()));
    connect(leAccount,SIGNAL(returnPressed()),this,SLOT(login()));

    connect(pbLogin,SIGNAL(clicked(bool)),this,SLOT(login()));
}

void FLoginWidget::login()
{
    pbLogin->setDisabled(true);

    QString error = "";
    QString errorTitle = "";

    if(leAccount->text().isEmpty())
    {
        errorTitle = "Username required";
        error = "Please enter your username.";
    }
    else if(leAccount->text().isEmpty())
    {
        errorTitle = "Password required";
        error = "Please enter your password.";
    }
    else
    {
        this->login(leAccount->text(),lePassword->text());
    }

    if(!error.isEmpty())
    {
        QMessageBox::critical(this,errorTitle, error);
    }
}

void FLoginWidget::login(const QString user, const QString pass)
{
    this->client->login(user,pass);
}

void FLoginWidget::onLoginError(QString error)
{
    QMessageBox::critical(this,"Login Error", error);
    pbLogin->setEnabled(true);
}

void FLoginWidget::onLoginSuccess(LoginTicket ticket)
{
    QStringList items;

    for(unsigned i=0; i<ticket.characters.size();i++)
        items << QString(ticket.characters[i].c_str());

    QString character = QInputDialog::getItem(this,"Character","Select character",items,ticket.defaultCharacterIndex);
    ticket.selectedCharacter = character.toStdString();

    emit loginSuccess(ticket);
}

void FLoginWidget::onLoginSuccess(QString string)
{
    QMessageBox::information(this,"Login Successful", string);
    pbLogin->setEnabled(true);
}
