#include "dialogaccueil.h"
#include "ui_dialogaccueil.h"

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

    // Masquage du 3e bouton de barreMenuFiche
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

    // SIGNAUX et SLOTS
    QObject::connect(m_menu.pushButton_2, SIGNAL(clicked()), qApp, SLOT(quit()));
    QObject::connect(m_menu.pushButton_1, SIGNAL(clicked()), this, SLOT(reset()));
    QObject::connect(ui->button_Effacer, SIGNAL(clicked()), ui->lineEdit_Recherche, SLOT(clear()));
    QObject::connect(ui->button_Ok, SIGNAL(clicked()), this, SLOT(chercherClients()));
}

DialogAccueil::~DialogAccueil()
{
    delete m_db;
    // delete m_settings;
    delete ui;
}

void DialogAccueil::reset()
{
    ui->lineEdit_Recherche->clear();
    ui->tableView_Resultats->clearSpans();
}

void DialogAccueil::chercherClients()
{
    QString client = ui->lineEdit_Recherche->text();
    if (client.isEmpty())
        faireAutreChose();
    else
    {
        /*
        m_db = new BDD(m_settings->getTypeConnection(),
                       m_settings->getHost(),
                       m_settings->getDataBaseName(),
                       m_settings->getUser(),
                       m_settings->getPassword());
*/
        m_db = new BDD();

        if (m_db->isValid())
        {
            qDebug() << "Connexion ouverte";
        }
        else
        {
            // QDebug("Pas de connexion");
        }
        // construire la requête de recherche
        // exécuter la requête
        // récupérer le résultat
        // compter le nombre de lignes de résultats
        // afficher les résultats

        m_db->close();
    }
}

void DialogAccueil::faireAutreChose()
{

}
