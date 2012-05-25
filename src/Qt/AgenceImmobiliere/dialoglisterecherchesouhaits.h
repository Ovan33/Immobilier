#ifndef DIALOGLISTERECHERCHESOUHAITS_H
#define DIALOGLISTERECHERCHESOUHAITS_H

#include <QDialog>
#include <widgetsouhait.h>
#include <Souhait.h>
#include <Bien.h>
#include <BDD.h>
#include <ui_barreMenuFiche.h>

namespace Ui {
    class DialogListeRechercheSouhaits;
}

class DialogListeRechercheSouhaits : public QDialog
{
    Q_OBJECT

public:
    explicit DialogListeRechercheSouhaits(Bien* bien, QWidget *parent = 0);
    ~DialogListeRechercheSouhaits();

private:
    Ui::DialogListeRechercheSouhaits *ui;
    Ui::barreMenuFiche m_menu;
    Bien* m_bien;
    BDD *m_db;
    QList<Souhait *> m_listeSouhaits;

    void remplirListeSouhaits();
    void rechercherSouhaits();
    int souhaitExistant(Souhait* souhait);
    // WidgetSouhait* creerWidget(Souhait* souhait, int ligne);
    void creerWidget(Souhait* souhait, int ligne);
    Souhait* creerSouhait();
    void ajouterSouhait(Souhait* s);
};

#endif // DIALOGLISTERECHERCHESOUHAITS_H
