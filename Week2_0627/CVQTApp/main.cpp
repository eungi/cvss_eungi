#include "cvqtapp.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CVQTApp w;
    w.show();

    return a.exec();
}
