#include <QtGui/QApplication>
#include "Immo.h"

// Ne pas TOUCHER ce FICHIER MERCI =)

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Immo w;
    w.show();

    return a.exec();
}
