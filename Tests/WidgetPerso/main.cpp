#include <QApplication>
#include "MaFenetre.h"

int main (int argc, char *argv[])
{
    QApplication app(argc, argv);
    MaFenetre mfn;
    mfn.show();

    return app.exec();
}
