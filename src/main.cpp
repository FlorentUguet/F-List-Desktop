#include "tests.h"
#include <QApplication>

#include "utils/jsonutils.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //qRegisterMetaType<LoginTicket>("LoginTicket");

    Tests::Messenger();

    return a.exec();
}
