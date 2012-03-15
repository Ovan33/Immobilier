#include <QtGui/QApplication>
#include "sql_gui.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SQL_GUI w;
    w.show();

    return a.exec();
}
