#ifndef DIALOGACCUEIL_H
#define DIALOGACCUEIL_H

#include <QDialog>
#include <ui_barreMenuFiche.h>
#include <ui_accueilResultat.h>
#include <widgetclient.h>
#include "BDD.h"
#include "Parametre.h"
#include <dialogbien.h>

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

    BDD *m_db;
    DialogBien *m_dialogBien;

    void faireAutreChose();
    void creerSlots(WidgetClient client);

public slots:
    void reset();
    void chercherClients();
};

#endif // DIALOGACCUEIL_H
