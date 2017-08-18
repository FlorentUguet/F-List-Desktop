#ifndef FSERVERDEBUGWIDGET_H
#define FSERVERDEBUGWIDGET_H

#include <QtWidgets>
#include <QDebug>

#include "controller/fclient.h"

class FServerDebugWidget : public QWidget
{
    Q_OBJECT
public:
    FServerDebugWidget(QWidget *parent = nullptr);

signals:
    void sendMessage(QString message);

public slots:
    void sendMessage();
    void messageReceived(QString message);

private:
    QTextBrowser *browser;
    QLineEdit *lineEdit;

    FClient *client = 0;
};

#endif // FSERVERDEBUGWIDGET_H
