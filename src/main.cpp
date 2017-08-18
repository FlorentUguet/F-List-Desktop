#include "tests.h"
#include <QApplication>

#include "utils/jsonutils.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //qRegisterMetaType<LoginTicket>("LoginTicket");

    Tests::LoginWidget();

    return a.exec();
}
