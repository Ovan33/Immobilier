#include <QtGui/QApplication>
#include "Immo.h"

#include "dialogclient.h"

// Ne pas TOUCHER ce FICHIER MERCI =)

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Immo w;

    // Ville cado("Cadaujac","33140");
    // Client client(1, "NomClient", "AdresseClient", "TelClient", cado);
    // Client *cl = &client;
    // cl = *client;
    // DialogClient dc(cl);
    // dc.setClient(cl);
    // dc.setParent(this);

    // dc.exec();
    w.show();

    return a.exec();
}
