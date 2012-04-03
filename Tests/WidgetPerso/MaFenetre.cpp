#include "MaFenetre.h"

MaFenetre::MaFenetre()
{
    setFixedSize(220,220);
    QString nomClient = "Icham Dupont";

    // Construction du widget en lui passant en paramètre une QString
    // puis monWidgetPerso devient enfant de MaFenetre;
    monWidgetPerso = new MonWidget(nomClient);
    monWidgetPerso->setParent(this);
    monWidgetPerso->show();
}

MaFenetre::~MaFenetre()
{
    delete monWidgetPerso;
}
