#ifndef FCONSOLEWIDGET_H
#define FCONSOLEWIDGET_H

#include <QtWidgets>

class FConsoleWidget : public QWidget
{
    Q_OBJECT
public:
    FConsoleWidget(QWidget *parent = nullptr);

signals:
    void sendCommand(QString command);

public slots:
    void writeLine(QString text);

    void commandReceived(QString command);
    void commandSent(QString command);

private:
    QTextBrowser *console;
    QLineEdit *input;
};

#endif // FCONSOLEWIDGET_H
