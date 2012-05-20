#ifndef DIALOGCLIENT_H
#define DIALOGCLIENT_H

#include <QDialog>
#include <ui_barreMenuFiche.h>
#include <QList>
#include <Client.h>
#include <BDD.h>

namespace Ui {
    class DialogClient;
}

class DialogClient : public QDialog
{
    Q_OBJECT

public:
    explicit DialogClient(QWidget *parent = 0);
    DialogClient(Client *client, QWidget *parent=0);
    ~DialogClient();

private:
    Ui::DialogClient *ui;
    Ui::barreMenuFiche m_menu;
    Client *m_client;
    QList <Ville *> m_listeVilles;
    BDD *m_db;
    bool changed;
    bool checkData();

public slots:
    void valider();
    void fermer();
    void setEtat(QString);
    void changerLabel(QString);
    void chercherVilles();
};

#endif // DIALOGCLIENT_H
