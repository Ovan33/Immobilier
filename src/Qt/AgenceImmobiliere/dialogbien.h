#ifndef DIALOGBIEN_H
#define DIALOGBIEN_H

#include <QDialog>
#include <ui_barreMenuFiche.h>
#include <Bien.h>
#include <Client.h>
#include <BDD.h>

namespace Ui {
    class DialogBien;
}

class DialogBien : public QDialog
{
    Q_OBJECT

public:
    explicit DialogBien(QWidget *parent = 0);
    DialogBien(Bien *bien, QWidget *parent=0);
    DialogBien(Client *client, QWidget *parent=0);
    ~DialogBien();

private:
    Ui::DialogBien *ui;
    Ui::barreMenuFiche m_menu;
    Bien *m_bien;
    BDD *m_db;
    QList <Ville *> m_listeVilles;

public slots:
    void chercherVilles();
    void enableRechercherVilles(QString);
};

#endif // DIALOGBIEN_H
