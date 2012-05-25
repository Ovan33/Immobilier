#ifndef DIALOGLISTEBIENS_H
#define DIALOGLISTEBIENS_H

#include <ui_barreMenuFiche.h>
#include <QDialog>
#include <QList>
#include <Client.h>
#include <Bien.h>
#include <dialogbien.h>
#include <BDD.h>
#include <dialoglisterecherchesouhaits.h>

namespace Ui {
    class DialogListeBiens;
}

class DialogListeBiens : public QDialog
{
    Q_OBJECT

public:
    explicit DialogListeBiens(QWidget *parent = 0);
    DialogListeBiens(Client *client, QWidget *parent = 0);
    ~DialogListeBiens();

private:
    Ui::DialogListeBiens *ui;
    Ui::barreMenuFiche m_menu;

    Client *m_client;
    QList<Bien *> m_listeBiens;
    DialogBien *m_dialogBien;
    DialogListeRechercheSouhaits *m_listeSouhaits;
    BDD *m_db;
    Bien *m_bienCourant;

    void chercherBiens();

public slots:
    void nouveauBien();
    void ouvrirBien(int);
    void ouvrirListeSouhaits(int);
};

#endif // DIALOGLISTEBIENS_H
