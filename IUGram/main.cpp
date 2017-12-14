#include "iugram.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    IUGram first_window;
    first_window.show();

    return a.exec();
}
