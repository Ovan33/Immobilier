#ifndef MAFENETRE_H
#define MAFENETRE_H

#include <QApplication>
#include <QWidget>
#include <QString>
#include "MonWidget.h"

/*
  Une fenêtre personnelle dont le seul contenu est un widget perso
  de type MonWidget
  */

class MaFenetre : public QWidget
{
    private:
        MonWidget *monWidgetPerso;

    public:
        MaFenetre();
        ~MaFenetre();
};

#endif // MAFENETRE_H
