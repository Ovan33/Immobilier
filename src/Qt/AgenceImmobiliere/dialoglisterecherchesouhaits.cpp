#include "dialoglisterecherchesouhaits.h"
#include "ui_dialoglisterecherchesouhaits.h"
#include <QMessageBox>
#include <QSqlQuery>

DialogListeRechercheSouhaits::DialogListeRechercheSouhaits(Bien* bien, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogListeRechercheSouhaits)
{
    ui->setupUi(this);
    this->setWindowTitle("Gestion de biens immobiliers");
    m_bien = bien;
    m_menu.setupUi(ui->widget_barreMenu);
    m_menu.label_fenetre->setText("Correspondance bien - souhaits");
    m_menu.pushButton_3->setVisible(false);
    m_menu.pushButton_2->setVisible(false);
    m_menu.pushButton_1->setToolTip("fermer la fenêtre");
    m_menu.pushButton_1->setIcon(QIcon(":/app/back96"));
    ui->label_Prix->setText(QString::number(m_bien->getPrix()));
    ui->label_SurfHab->setText(QString::number(m_bien->getSurfHabitable()));
    ui->label_SurfJard->setText(QString::number(m_bien->getSurfJardin()));
    ui->label_Ville->setText(m_bien->getVille()->getNom()+"("+m_bien->getVille()->getCodePostal()+")");

    //Signaux et slots
    QObject::connect(m_menu.pushButton_1,SIGNAL(clicked()),this,SLOT(close()));

    //Remplissage de la liste des souhaits
    remplirListeSouhaits();
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
            while (requete.next())
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
                // liste non vide
                // ajout souhait ou ajout ville à souhait existant
                if (m_listeSouhaits.size() > 0)
                {
                    int i = souhaitExistant(souhaitCourant);
                    if (i == -1)
                        ajouterSouhait(souhaitCourant);
                    else
                    {
                        foreach (Ville *v, m_listeSouhaits[i]->getVilles())
                        {
                            if (v->getNum() != souhaitCourant->getVilles().at(i)->getNum())
                            {
                                Ville *ville = new Ville(requete.value(6).toInt(),requete.value(5).toString(),requete.value(7).toString());
                                m_listeSouhaits[i]->modifierVilles(ville);
                            }
                        }
                    }
                }
                // liste vide : ajout souhait
                else
                {
                    ajouterSouhait(souhaitCourant);
                }
            }
        }
    }
    m_db->close();
}

void DialogListeRechercheSouhaits::remplirListeSouhaits()
{
    int ligne = 0;
    rechercherSouhaits();
    if(m_listeSouhaits.size()<1)
        QMessageBox::information(this,"Liste de souhaits","Aucun souhait correspondant à ce bien");
    else
    {
        foreach(Souhait* s, m_listeSouhaits)
            creerWidget(s,ligne++);
    }
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

void DialogListeRechercheSouhaits::ajouterSouhait(Souhait *s)
{
    m_listeSouhaits.append(s);
}

void DialogListeRechercheSouhaits::creerWidget(Souhait* souhait, int ligne)
{
    WidgetSouhait *souhaitUi = new WidgetSouhait(souhait);
    souhaitUi->setBudgetMax(souhait->getBudget());
    souhaitUi->setSurfaceHabitableSouhaitee(souhait->getSurfaceHabitable());
    souhaitUi->setSurfaceJardinSouhaitee(souhait->getSurfaceJardin());

    ui->tableWidget_ListeSouhaits->setColumnWidth(0,souhaitUi->width());
    ui->tableWidget_ListeSouhaits->setRowHeight(ligne,souhaitUi->height());
    ui->tableWidget_ListeSouhaits->setCellWidget(ligne,0,souhaitUi);

    /* SIGNAUX et SLOTS à ajouter */
}

