#include "tests.h"

void Tests::LoginWidget()
{
    FLoginWidget *w = new FLoginWidget();
    w->show();
}

void Tests::Messenger()
{
    FMessengerWidget *m = new FMessengerWidget(0);
    m->show();
}
