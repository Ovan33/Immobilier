#include "dialoglisterecherchesouhaits.h"
#include "ui_dialoglisterecherchesouhaits.h"
#include <QSqlQuery>

DialogListeRechercheSouhaits::DialogListeRechercheSouhaits(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogListeRechercheSouhaits)
{
    ui->setupUi(this);
}

DialogListeRechercheSouhaits::~DialogListeRechercheSouhaits()
{
    delete ui;
}

void DialogListeRechercheSouhaits::rechercherSouhaits()
{
    // Query
    m_db = new BDD();
    if (m_db->ouvrir())
    {
        QSqlQuery requete(m_db->getDb());
        // ----------------------------------------
        // Reste à gérer les villes dans la requête
        // ----------------------------------------
        QString reqText = "select souhaits.num_s, souhaits.num_c, souhaits.budget_max_s, souhaits.budget_max_s, souhaits.surface_hab_min_s, souhaits.surface_jardin_min_s, ";
        reqText += " villes_souhaitees.num_v, villes.nom_v from souhaits";
        reqText += " inner join villes_souhaitees on souhaits.num_s=villes_souhaitees.num_s";
        reqText += " inner join villes on villes.num_v=villes_souhaitees.num_v";
        reqText += " where budget_max_s < :prixMax";
        reqText += " and budget_max_s > :prixMin";
        reqText += " and surface_hab_min_s < :surfHabMinMax";
        reqText += " and surface_hab_min_s > :surfHabMinMin";
        reqText += " order by num_s";
        int prixMax = ui->label_Prix->text().toInt() * 1.05;
        int prixMin = ui->label_Prix->text().toInt() * 0.95;
        int surfHabMinMax = ui->label_SurfHab->text().toInt() * 1.05;
        int surfHabMinMin = ui->label_SurfHab->text().toInt() * 0.95;
        requete.prepare(reqText);
        requete.bindValue(":prixMax",prixMax);
        requete.bindValue(":prixMin",prixMin);
        requete.bindValue(":surfHabMinMax",surfHabMinMax);
        requete.bindValue(":surfHabMinMin",surfHabMinMin);

        // Pour chaque résultat
        if (requete.exec())
        {
            //  Si liste non vide
            if (m_listeSouhaits.size() > 0)
            {

                    // récupérer le numéro du souhait
                    // comparer aux souhaits de la liste
                        // si existant ajouter la ville dans la liste de ville du souhait
                        // sinon créer nouveauSouhait
                //  Sinon créer nouveauSouhait (souhait0)

            }
        }
    }
    m_db->close();
    // return m_listeSouhaits;
}

void DialogListeRechercheSouhaits::remplirListeSouhaits()
{

}

int DialogListeRechercheSouhaits::souhaitExistant(Souhait* souhait)
{
    // Souhait* s;
    foreach (Souhait* s, m_listeSouhaits)
    {
        if (souhait->getNum() == s->getNum())
            return m_listeSouhaits.indexOf(s);
    }
    return -1;
}

