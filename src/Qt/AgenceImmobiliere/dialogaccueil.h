#ifndef DIALOGACCUEIL_H
#define DIALOGACCUEIL_H

#include <QDialog>
#include <ui_barreMenuFiche.h>
#include "BDD.h"
#include "Parametre.h"

namespace Ui {
    class DialogAccueil;
}

class DialogAccueil : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAccueil(QWidget *parent = 0);
    ~DialogAccueil();

private:
    Ui::DialogAccueil *ui;
    Ui::barreMenuFiche m_menu;

    // BDD *m_db;
    Parametre *m_settings;
    void faireAutreChose();


public slots:
    void reset();
    void chercherClients();
};

#endif // DIALOGACCUEIL_H
