#include "dialoglisterecherchesouhaits.h"
#include "ui_dialoglisterecherchesouhaits.h"
#include <QSqlQuery>

DialogListeRechercheSouhaits::DialogListeRechercheSouhaits(Bien* bien, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogListeRechercheSouhaits)
{
    ui->setupUi(this);
    m_bien = bien;
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
        // Manque le jardin //
        QSqlQuery requete(m_db->getDb());
        QString reqText = "select souhaits.num_s, souhaits.num_c, souhaits.budget_max_s, souhaits.surface_hab_min_s, souhaits.surface_jardin_min_s, ";
        reqText += " villes_souhaitees.num_v, villes.nom_v, villes.code_postal_v, ";
        reqText += " clients.nom_c, clients.adresse_c, clients.tel_c, clients.num_v, clients.num_a ";
        reqText += " from souhaits";
        reqText += " inner join villes_souhaitees on souhaits.num_s=villes_souhaitees.num_s";
        reqText += " inner join villes on villes.num_v=villes_souhaitees.num_v";
        reqText += " where budget_max_s < :prixMax";
        reqText += " and budget_max_s > :prixMin";
        reqText += " and surface_hab_min_s < :surfHabMinMax";
        reqText += " and surface_hab_min_s > :surfHabMinMin";
        reqText += " order by num_s";
        int prixMax = m_bien->getPrix() * 1.05;
        int prixMin = m_bien->getPrix() * 0.95;
        int surfHabMinMax = m_bien->getSurfHabitable() * 1.05;
        int surfHabMinMin = m_bien->getSurfHabitable() * 0.95;
        requete.prepare(reqText);
        requete.bindValue(":prixMax",prixMax);
        requete.bindValue(":prixMin",prixMin);
        requete.bindValue(":surfHabMinMax",surfHabMinMax);
        requete.bindValue(":surfHabMinMin",surfHabMinMin);
        if (requete.exec())
        {
            Souhait* souhaitCourant;
            QList<Ville *> listeVilles;
            QSqlQuery req_ville(m_db->getDb());
            req_ville.prepare("select * from villes where num_v=:numVille");
            req_ville.bindValue(":numVille",requete.value(11).toInt());
            if (req_ville.exec())
                souhaitCourant = new Souhait(requete.value(0).toUInt(),
                                             requete.value(2).toUInt(),
                                             requete.value(3).toUInt(),
                                             requete.value(4).toUInt(),
                                             listeVilles,
                                             new Client(requete.value(1).toInt(),
                                                        requete.value(8).toString(),
                                                        requete.value(9).toString(),
                                                        requete.value(10).toString(),
                                                        new Ville(req_ville.value(0).toUInt(),
                                                                  req_ville.value(1).toString(),
                                                                  req_ville.value(2).toString()),
                                                        requete.value(12).toInt()));
            if (m_listeSouhaits.size() > 0)
            {
                for (int i =0; i< m_listeSouhaits.size(); i++)
                {
                    if(m_listeSouhaits[i]->getNum() == souhaitCourant->getNum())
                    {
                       Ville *ville = new Ville(requete.value(6).toInt(),requete.value(5).toString(),requete.value(7).toString());
                       m_listeSouhaits[i]->modifierVilles(ville);
                    }
                    else
                    {
                        QList<Ville *> m_listeVilles;
                        Ville *ville = new Ville(requete.value(6).toInt(),requete.value(5).toString(),requete.value(7).toString());
                        m_listeVilles.append(ville);


//Souhait(unsigned int numSouhait(0),unsigned int budgetMax(2), unsigned int surfHabMin(3), unsigned int surfJardMin(4), QList<Ville *> ville, Client *client);
                        // Souhait *souhait = new Souhait(requete.value(0).toInt(), requete.value(2).toInt(), requete.value(3).toInt(), requete.value(4).toInt(),m_listeVilles, m_client);
                        // this->m_listeSouhaits.append(souhait);
                    }
                }

                    // récupérer le numéro du souhait
                    // comparer aux souhaits de la liste
                        // si existant ajouter la ville dans la liste de ville du souhait
                        // sinon créer nouveauSouhait
                //  Sinon créer nouveauSouhait (souhait0)

            }
            else
            {
                Souhait* souhait = creerSouhait();
                m_listeSouhaits.append(souhait);
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
    foreach (Souhait* s, m_listeSouhaits)
    {
        if (souhait->getNum() == s->getNum())
            return m_listeSouhaits.indexOf(s);
    }
    return -1;
}

Souhait * DialogListeRechercheSouhaits::creerSouhait()
{
    // Souhait* s = new Souhait();
}

