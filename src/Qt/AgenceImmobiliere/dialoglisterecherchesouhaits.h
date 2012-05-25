#ifndef DIALOGLISTERECHERCHESOUHAITS_H
#define DIALOGLISTERECHERCHESOUHAITS_H

#include <QDialog>
#include <widgetsouhait.h>
#include <Souhait.h>
#include <Bien.h>
#include <BDD.h>

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
    Bien* m_bien;
    BDD *m_db;
    QList<Souhait *> m_listeSouhaits;

    void remplirListeSouhaits();
    void rechercherSouhaits();
    int souhaitExistant(Souhait* souhait);
    WidgetSouhait* creerWidget(Souhait souhait);
    Souhait* creerSouhait();
};

#endif // DIALOGLISTERECHERCHESOUHAITS_H
