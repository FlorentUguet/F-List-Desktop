#include "fconsolewidget.h"

FConsoleWidget::FConsoleWidget(QWidget *parent) : QWidget(parent)
{
    console = new QTextBrowser(this);
    input = new QLineEdit(this);

    QVBoxLayout *l = new QVBoxLayout;
    l->addWidget(console);
    l->addWidget(input);
    setLayout(l);
}

void FConsoleWidget::writeLine(QString text)
{
    this->console->setText(this->console->toPlainText() + QString('\n') + text);
}

void FConsoleWidget::commandReceived(QString command)
{
    this->writeLine(QString("<< ") + command);
}

void FConsoleWidget::commandSent(QString command)
{
    this->writeLine(QString(">> ") + command);
}
