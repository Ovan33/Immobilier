#include <QtGui/QApplication>
// #include "mainwindow.h"
#include <dialogaccueil.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // MainWindow w;
    // w.show();
    DialogAccueil da;
    return da.exec();

    // return a.exec();
}
