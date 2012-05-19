#include "dialogaccueil.h"
#include "ui_dialogaccueil.h"

// #include <widgetclient.h>
#include <QMessageBox>

/*
  Constructeur
  */

DialogAccueil::DialogAccueil(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAccueil)
{
    ui->setupUi(this);
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("utf8"));
    this->setWindowTitle("Accueil");
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
    //Préparation de l'interface
    ui->button_Ajouter->setToolTip("Créer un nouveau client");
    ui->button_Effacer->setToolTip("Effacer la zone de recherche");
    ui->button_Ok->setToolTip("Lancer la recherche");
    ui->tableWidget_resultats->setColumnCount(1);
    ui->tableWidget_resultats->verticalHeader()->hide();
    ui->tableWidget_resultats->horizontalHeader()->hide();
    // SIGNAUX et SLOTS
    QObject::connect(m_menu.pushButton_2, SIGNAL(clicked()), qApp, SLOT(quit()));
    QObject::connect(m_menu.pushButton_1, SIGNAL(clicked()), this, SLOT(reset()));
    QObject::connect(ui->button_Effacer, SIGNAL(clicked()), ui->lineEdit_Recherche, SLOT(clear()));
    QObject::connect(ui->button_Ok, SIGNAL(clicked()), this, SLOT(chercherClients()));
    QObject::connect(ui->button_Ajouter, SIGNAL(clicked()),this,SLOT(nouveauClient()));
}

DialogAccueil::~DialogAccueil()
{
    delete m_db;
    delete m_clientCourant;
    delete ui;
}

void DialogAccueil::reset()
{
    ui->lineEdit_Recherche->clear();
    ui->tableWidget_resultats->clearContents();
    ui->tableWidget_resultats->clear();
    ui->tableWidget_resultats->setRowCount(0);
}

void DialogAccueil::chercherClients()
{
    QString client = ui->lineEdit_Recherche->text().toUpper();
    if (client.isEmpty())
        QMessageBox::information(this,"Recherche client", "Merci de saisir au moins une lettre dans la zone de recherche");
    else
    {
        QString requete = "select CLIENTS.NUM_C, CLIENTS.nom_c, CLIENTS.adresse_c, CLIENTS.tel_c, ";
        requete += "VILLES.nom_v, VILLES.code_postal_v, ";
        requete += "(select count(BIENS.num_b) from Biens where biens.num_c=clients.num_c) as NbBiens, ";
        requete += "(select count(SOUHAITS.num_s) from Souhaits where souhaits.num_c=clients.num_c) as NbSouhaits ";
        requete += "from CLIENTS INNER JOIN VILLES on VILLES.NUM_V=CLIENTS.NUM_V ";
        requete += "left outer JOIN BIENS on BIENS.num_c=CLIENTS.num_c ";
        requete += "left outer JOIN SOUHAITS on SOUHAITS.num_c=CLIENTS.num_c ";
        requete += "where CLIENTS.nom_c like'" + client + "%'";
        requete += "group by clients.num_c, clients.nom_c, clients.adresse_c,clients.tel_c, villes.nom_v,villes.code_postal_v ";
        requete += "order by clients.num_c";

        m_db = new BDD();
        if (m_db->ouvrir())
        {
            QSqlQuery resultat;
            if (resultat.exec(requete))
            {
                if (resultat.size() < 1)
                    QMessageBox::information(this,"Recherche client", "Aucun client trouvé");
                else
                {
                    // Initialisations
                    ui->tableWidget_resultats->setRowCount(resultat.size());
                    int ligne = 0;
                    while (resultat.next())
                    {
                        WidgetClient *clientUi = new WidgetClient();
                        Ville ville(resultat.value(4).toString(),resultat.value(5).toString());
                        Client client(resultat.value(0).toInt(),resultat.value(1).toString(),resultat.value(2).toString(),resultat.value(3).toString(),ville);
                        int nbBiens = resultat.value(6).toInt();
                        int nbSouhaits = resultat.value(7).toInt();
                        clientUi->setNom(client.getNom());
                        clientUi->setVille(ville.getNom());
                        clientUi->setAdresse(client.getAdresse());
                        clientUi->setTelephone(client.getTel());
                        clientUi->setCodePostal(ville.getCodePostal());
                        //Nb souhait = 0
                        if (nbBiens < 1)
                        {
                            clientUi->setImageSouhait(QPixmap(":/app/add_souhait96"));
                            m_dialogSouhait = new DialogSouhait();
                            QObject::connect(clientUi->getBoutonSouhait(),SIGNAL(clicked()),m_dialogSouhait,SLOT(exec()));
                        } else {
                        // Sinon slot si au moins un bien
                        }

                        //Nb bien = 0
                        if (nbSouhaits < 1)
                        {
                            clientUi->setImageBien(QPixmap(":/app/add_bien96"));
                            m_dialogBien = new DialogBien();
                            QObject::connect(clientUi->getBoutonBien(),SIGNAL(clicked()), m_dialogBien,SLOT(exec()));
                        } else {
                        // Slot si au moins un souhait
                        }

                        ui->tableWidget_resultats->setColumnWidth(0,ui->tableWidget_resultats->width()-15);
                        ui->tableWidget_resultats->setRowHeight(ligne,clientUi->height());
                        ui->tableWidget_resultats->setCellWidget(ligne,0,clientUi);

                        ligne++;
                    }
                }
            }
        }
        m_db->close();
    }
}

void DialogAccueil::nouveauClient()
{
    Ville ville;
    m_clientCourant = new Client(0,ui->lineEdit_Recherche->text(),QString(""),QString(""),ville);
    this->m_dialogClient = new DialogClient(m_clientCourant);
    m_dialogClient->exec();
}
