#include "dialoglistesouhait.h"
#include "ui_dialoglistesouhait.h"

//DialogListeSouhait::DialogListeSouhait(QWidget *parent) :
//    QDialog(parent),
//    ui(new Ui::DialogListeSouhait)
//{
//    ui->setupUi(this);
//}

DialogListeSouhait::DialogListeSouhait(Client *client, QWidget *parent):
    QDialog(parent),
    ui(new Ui::DialogListeSouhait)
{
    ui->setupUi(this);
    m_client = client;
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("utf8"));
    this->setWindowTitle("Liste des souhaits");
    m_menu.setupUi(ui->widget_barreMenu);
    m_menu.label_fenetre->setText("Souhaits");
    m_menu.image_fenetre->setPixmap(QPixmap(":/app/souhait96"));
    m_menu.pushButton_3->setVisible(false);
    // Bouton de fermeture
    m_menu.pushButton_1->setIcon(QIcon(":/app/back96"));
    m_menu.pushButton_1->setToolTip("Fermer la fenêtre");
    // Bouton Quitter
    m_menu.pushButton_2->setIcon(QIcon(":/app/quitter96"));
    m_menu.pushButton_2->setToolTip("Quitter l'application");
    //Informations client
    ui->label_NomClient->setText(client->getNom());

    ui->tableWidget_listeSouhaits->setColumnCount(1);
    ui->tableWidget_listeSouhaits->verticalHeader()->hide();
    ui->tableWidget_listeSouhaits->horizontalHeader()->hide();

    chercherSouhait();
    // SIGNAUX et SLOTS
    QObject::connect(m_menu.pushButton_1,SIGNAL(clicked()),this,SLOT(close()));
    QObject::connect(m_menu.pushButton_2,SIGNAL(clicked()),qApp,SLOT(quit()));
    QObject::connect(ui->pushButton_ajouterSouhait, SIGNAL(clicked()),this,SLOT(nouveauSouhait()));
}

DialogListeSouhait::~DialogListeSouhait()
{
    delete ui;
}

void DialogListeSouhait::chercherSouhait()
{
    m_db = new BDD();
    if (m_db->ouvrir())
    {
        QSqlQuery requete(m_db->getDb());
        requete.prepare("SELECT souhaits.num_s, souhaits.num_c, souhaits.budget_max_s, souhaits.surface_hab_min_s, souhaits.surface_jardin_min_s, villes.nom_v, villes.num_v, villes.code_postal_v, clients.nom_c FROM souhaits INNER JOIN clients ON souhaits.num_c = clients.num_c INNER JOIN villes_souhaitees ON souhaits.num_s = villes_souhaitees.num_s INNER JOIN villes ON villes_souhaitees.num_v = villes.num_v Where clients.num_c =:numClient");

        requete.bindValue(":numClient", QString::number(m_client->getNum()));
        if (requete.exec())
        {
            if (requete.size() < 1)
                QMessageBox::information(this,"Recherche client", "Aucun souhait trouvé");
            else
            {
                //Initialisations
                ui->tableWidget_listeSouhaits->setRowCount(requete.size());
                int ligne = 0;
                while (requete.next())
                {
                    WidgetSouhait *souhaitUi = new WidgetSouhait();
                    Ville *ville = new Ville(requete.value(6).toInt(),requete.value(5).toString(),requete.value(7).toString());
                    Souhait *souhait = new Souhait(requete.value(2).toInt(), requete.value(3).toInt(), requete.value(4).toInt(), ville, m_client);
                    souhaitUi->setBudgetMax(souhait->getBudget());
                    souhaitUi->setSurfaceHabitableSouhaitee(souhait->getSurfaceHabitable());
                    souhaitUi->setSurfaceJardinSouhaitee(souhait->getSurfaceJardin());

//                    int largeur = ui->tableWidget_listeSouhaits->width();
//                    souhaitUi->setMinimumWidth(largeur);

                    ui->tableWidget_listeSouhaits->setColumnWidth(0,souhaitUi->width());
                    ui->tableWidget_listeSouhaits->setRowHeight(ligne,souhaitUi->height());
                    ui->tableWidget_listeSouhaits->setCellWidget(ligne,0,souhaitUi);
                    //ui->tableWidget_listeSouhaits->setAlternatingRowColors(true);
                    //ui->tableWidget_listeSouhaits->setStyleSheet("alternate-background-color: yellow;background-color: gray;");

                    ligne++;

                }
            }
        }
        m_db->close();
    }
}

void DialogListeSouhait::nouveauSouhait()
{
    Ville *newVille = new Ville();
    Souhait *newSouhait = new Souhait(0,0,0,newVille,m_client);
    m_dialogSouhait = new DialogSouhait(newSouhait, this);
    m_dialogSouhait->exec();
}
