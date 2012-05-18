#include "dialogaccueil.h"
#include "ui_dialogaccueil.h"

#include <widgetclient.h>
#include <QMessageBox>


/*
  Constructeur
  */

DialogAccueil::DialogAccueil(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAccueil)
{
    ui->setupUi(this);

    // Chargement des paramètres
    // m_settings = new Parametre();

    // Création de la barre de menu
    m_menu.setupUi(ui->widget_barreMenu);
    m_menu.label_fenetre->setText("Accueil");
    m_menu.image_fenetre->setPixmap(QPixmap(":/app/accueil"));

    // Masquage du 3e bouton de la barre de menu
    m_menu.pushButton_3->setVisible(false);

    // Bouton de reset
    m_menu.pushButton_1->setIcon(QIcon(":/app/rafraichir96"));
    m_menu.pushButton_1->setToolTip("Reset");

    // Bouton Quitter
    m_menu.pushButton_2->setIcon(QIcon(":/app/quitter96"));
    m_menu.pushButton_2->setToolTip("Quitter l'application");

    ui->button_Ajouter->setToolTip("Créer un nouveau client");
    ui->button_Effacer->setToolTip("Effacer la zone de recherche");
    ui->button_Ok->setToolTip("Lancer la recherche");
    ui->tableWidget_resultats->verticalHeader()->hide();
    ui->tableWidget_resultats->horizontalHeader()->hide();

    // SIGNAUX et SLOTS
    QObject::connect(m_menu.pushButton_2, SIGNAL(clicked()), qApp, SLOT(quit()));
    QObject::connect(m_menu.pushButton_1, SIGNAL(clicked()), this, SLOT(reset()));
    QObject::connect(ui->button_Effacer, SIGNAL(clicked()), ui->lineEdit_Recherche, SLOT(clear()));
    QObject::connect(ui->button_Ok, SIGNAL(clicked()), this, SLOT(chercherClients()));
}

DialogAccueil::~DialogAccueil()
{
    // delete m_db;
    // delete m_settings;
    delete ui;
}

void DialogAccueil::reset()
{
    ui->lineEdit_Recherche->clear();
    ui->tableWidget_resultats->clearContents();
    ui->tableWidget_resultats->clear();
}

void DialogAccueil::chercherClients()
{
    QString client = ui->lineEdit_Recherche->text().toUpper();
    if (client.isEmpty())
        faireAutreChose();
    else
    {
        m_db = new BDD();

        // construire la requête de recherche
        QString requete = "select CLIENTS.NUM_C, CLIENTS.nom_c, CLIENTS.adresse_c, CLIENTS.tel_c, VILLES.nom_v, VILLES.code_postal_v ";
        requete += "from CLIENTS INNER JOIN VILLES on VILLES.NUM_V=CLIENTS.NUM_V where CLIENTS.nom_c like '";
        requete += client;
        requete += "%';";

        // exécuter la requête et récupérer le résultat
        if (m_db->ouvrir())
        {
            QSqlQuery resultat;
            if (resultat.exec(requete))
            {
                // Si 0 contenu
                if (resultat.size() == -1)
                    QMessageBox::information(this,"Recherche client", "Aucun client trouvé");
                else
                {
                    // Initialisation du tableau de widgets
                    int cpt = resultat.size();
                    ui->tableWidget_resultats->setRowCount(cpt);
                    ui->tableWidget_resultats->setColumnCount(1);
                    int ligne = 0;
                    while (resultat.next())
                    {
                        ui->tableWidget_resultats->setColumnCount(1);
                        WidgetClient *client = new WidgetClient();
                        client->setNom(resultat.value(1).toString());
                        client->setVille(resultat.value(4).toString());
                        client->setAdresse(resultat.value(2).toString());
                        client->setTelephone(resultat.value(3).toString());
                        client->setCodePostal(resultat.value(5).toString());

                        if (ligne == 0)
                        {
                            // ui->tableWidget_resultats->setColumnWidth(0,client->width());
                            ui->tableWidget_resultats->setColumnWidth(0,ui->tableWidget_resultats->width()-15);
                        }
                        ui->tableWidget_resultats->setRowHeight(ligne,client->height());

                        // QWidget *client = new Ui::widget_Client;
                        // client.label_Nom->setText(resultat.value(1).toString());
                        ui->tableWidget_resultats->setCellWidget(ligne,0,client);

                        /*
                        ui->tableWidget_resultats->setColumnCount(4);
                        QTableWidgetItem *nom = new QTableWidgetItem(resultat.value(1).toString());
                        QTableWidgetItem *adresse = new QTableWidgetItem(resultat.value(2).toString());
                        QTableWidgetItem *tel = new QTableWidgetItem(resultat.value(3).toString());
                        QTableWidgetItem *ville = new QTableWidgetItem(resultat.value(4).toString());

                        ui->tableWidget_resultats->setItem(ligne,0,nom);
                        ui->tableWidget_resultats->setItem(ligne,1,adresse);
                        ui->tableWidget_resultats->setItem(ligne,2,tel);
                        ui->tableWidget_resultats->setItem(ligne,3,ville);
                        */
                        ligne++;
                    }
                }
            }
        }

        // afficher message d'information
        // sinon afficher les résultats

        m_db->close();
    }
}

void DialogAccueil::faireAutreChose()
{

}
