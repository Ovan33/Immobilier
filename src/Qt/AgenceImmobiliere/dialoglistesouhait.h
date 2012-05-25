#ifndef DIALOGLISTESOUHAIT_H
#define DIALOGLISTESOUHAIT_H

#include <QDialog>
#include <ui_barreMenuFiche.h>
#include <Client.h>
#include <BDD.h>
#include <QMessageBox>
#include <Souhait.h>
#include <widgetsouhait.h>
#include <Ville.h>
#include <dialogsouhait.h>

namespace Ui {
class DialogListeSouhait;
}

class DialogListeSouhait : public QDialog
{
    Q_OBJECT
    
public:
    //explicit DialogListeSouhait(QWidget *parent = 0);
    DialogListeSouhait(Client *client, QWidget *parent = 0);
    ~DialogListeSouhait();
    
private:
    Ui::DialogListeSouhait *ui;
    Ui::barreMenuFiche m_menu;

    Client *m_client;
    DialogSouhait *m_dialogSouhait;
    BDD *m_db;

    void chercherSouhait();

public slots:
    void nouveauSouhait();
};

#endif // DIALOGLISTESOUHAIT_H
