#ifndef DIALOGACCUEIL_H
#define DIALOGACCUEIL_H

#include <QDialog>
#include <ui_barreMenuFiche.h>
#include <ui_accueilResultat.h>
#include <widgetclient.h>
#include "BDD.h"
#include "Parametre.h"
#include <dialogbien.h>
#include <dialogsouhait.h>
#include <dialogclient.h>
#include <Client.h>
#include <QList>

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
    DialogSouhait *m_dialogSouhait;
    DialogClient *m_dialogClient;
    // QList *m_listeClients;

public slots:
    void reset();
    void chercherClients();
    void nouveauClient();
};

#endif // DIALOGACCUEIL_H
