#ifndef DIALOGLISTERECHERCHESOUHAITS_H
#define DIALOGLISTERECHERCHESOUHAITS_H

#include <QDialog>
#include <widgetsouhait.h>
#include <Souhait.h>
#include <BDD.h>

namespace Ui {
    class DialogListeRechercheSouhaits;
}

class DialogListeRechercheSouhaits : public QDialog
{
    Q_OBJECT

public:
    explicit DialogListeRechercheSouhaits(QWidget *parent = 0);
    ~DialogListeRechercheSouhaits();

private:
    Ui::DialogListeRechercheSouhaits *ui;
    BDD *m_db;
    QList<Souhait *> m_listeSouhaits;

    void remplirListeSouhaits();
    void rechercherSouhaits();
    int souhaitExistant(Souhait* souhait);
    WidgetSouhait* creerWidget(Souhait souhait);
    //BDD* getDb();

};

#endif // DIALOGLISTERECHERCHESOUHAITS_H
