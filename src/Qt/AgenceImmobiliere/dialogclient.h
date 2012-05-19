#ifndef DIALOGCLIENT_H
#define DIALOGCLIENT_H

#include <QDialog>
#include <ui_barreMenuFiche.h>
#include <Client.h>

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
    bool changed;
    bool checkData();

public slots:
    void valider();
    void fermer();
    void setEtat(QString);
    void changerLabel(QString);
};

#endif // DIALOGCLIENT_H
