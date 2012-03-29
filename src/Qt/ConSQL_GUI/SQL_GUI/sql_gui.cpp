#include "sql_gui.h"
#include "ui_sql_gui.h"


SQL_GUI::SQL_GUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SQL_GUI)
{
    ui->setupUi(this);
    connect(ui->actionNouveau_Client,SIGNAL(clicked()),this,SLOT(actionNouveau_Client()));


    // Création barre menu
    QMenuBar* menuBar = new QMenuBar(this); // création barre de menu
    // Menu Fichier
    QMenu* menuFile = new QMenu("Fichier"); // menu fichier
    menuBar->addMenu(menuFile); // ajout du menu fichier à la barre menu
    // Items
    menuFile->addAction("Open");
    menuFile->addSeparator();
    menuFile->addAction("Quitter", this, SLOT(close())); // Item Quitter
    setMenuBar(menuBar); // mettre la barre sur la fenetre principale
    //Menu Edition
    menuFile = new QMenu("Edition"); // menu Edition
    menuBar->addMenu(menuFile);
    // Items
    menuFile->addAction("Nouveau Client", this, SLOT(ajoutNewClient()));
    menuFile->addSeparator();


    ui->FenetreInfo->append("Connexion a la base de donnees...");
    connexionBDD();
    //requeteVille();
    //remplissageTV();
    //requeteClient();
    //TVClient();
    requeteNewClient();
    //requeteNewClient2();
    TVClient();
}

SQL_GUI::~SQL_GUI()
{
    delete ui;
}

void SQL_GUI::connexionBDD()
{
    db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("localhost");
    db.setDatabaseName("immo");
    db.setUserName("isirat");
    db.setPassword("isirat");
    // test chargement driver sql
    if (db.isDriverAvailable("QPSQL"))
        ui->FenetreInfo->append("Chargement driver ok");
    // test ouverture bdd
    if (db.open())
        ui->FenetreInfo->append("Connexion etablie");
    else ui->FenetreInfo->append("Connexion impossible !");
}

void SQL_GUI::requeteVille()
{
// Je declare une requete
    QSqlQuery query("SELECT villes FROM villes");
    // QsqlQuery::next() permet d'aller chercher le suivant tant qu'il y en a =)
    // Equivalent à [SELECT * FROM maTable;]
    while (query.next())
        {
           // Je range la valeur que me retourne query.next() dans un string...
           QString result = query.value(0).toString();
           // que j'affiche dans la FenetreRequete
           ui->FenetreRequete->append(result);

        }
}

void SQL_GUI::requeteClient()
{
    QSqlQuery query("SELECT nom_c, adresse_c, tel_c, nom_v, code_postal_v, prenom_a from CLIENTS INNER JOIN VILLES on villes.num_v=clients.num_v LEFT OUTER JOIN AGENTS on agents.num_a=clients.num_a;");
    while (query.next())
    {
        QString result = query.value(0).toString();
        ui->FenetreRequete->append(result);
    }
}

void SQL_GUI::TVClient()
{
    QSqlTableModel *model = new QSqlTableModel(this, db);
    model->setTable("clients");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();
    model->removeColumn(0); // don't show the ID
    model->setHeaderData(0, Qt::Horizontal, tr("Villes"));
    model->setHeaderData(1, Qt::Horizontal, tr("Agent"));
    model->setHeaderData(2, Qt::Horizontal, tr("Nom"));
    model->setHeaderData(3, Qt::Horizontal, tr("Adresse"));
    model->setHeaderData(4, Qt::Horizontal, tr("Tel"));
    ui->tableView->setModel(model);
    ui->tableView->setSortingEnabled(true); // fonction trie des colonnes
}

void SQL_GUI::remplissageTV()
{
    QSqlTableModel *model = new QSqlTableModel(this, db);
    model->setTable("villes");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();
    model->removeColumn(0); // don't show the ID
    model->setHeaderData(0, Qt::Horizontal, tr("Nom"));
    model->setHeaderData(1, Qt::Horizontal, tr("CP"));
    ui->tableView->setModel(model);
    ui->tableView->setSortingEnabled(true); // fonction trie des colonnes
}

void SQL_GUI::requeteNewClient(){
    // requete serialisable test OK

    ui->FenetreInfo->append("Preparation requete");
    QString error;
    QSqlQuery query;
    QString nomC = "Simpson Omer";
    QString adresseC = "3 rue de Springfield";
    QString telC = "0123456789";
    QString numA = "1";
    QString numV = "3";

    query.prepare("INSERT INTO clients(num_c, num_v, num_a, nom_c, adresse_c, tel_c)"
                  "VALUES (default, :num_v, :num_a, :nom_c, :adresse_c, :tel_c)");
    query.bindValue(":num_v", numV);
    query.bindValue(":num_a", numA);
    query.bindValue(":nom_a", nomC);
    query.bindValue(":adresse_c", adresseC);
    query.bindValue(":tel_c", telC);
    if (query.exec())
    {
        error = query.lastError().text();
        ui->FenetreInfo->append(error);
        ui->FenetreInfo->append("Requete ok");
    }
}

void SQL_GUI::requeteNewClient2()
{   // Requete de test -> ok

    QString error;
    ui->FenetreInfo->append("Preparation requete");
    QSqlQuery q;
    q.exec("INSERT INTO clients(num_c, num_v, num_a, nom_c, adresse_c, tel_c) VALUES (default, 3, 1, 'Tintin3', '14 rue de lespace', '0101010101')");
    error = q.lastError().text();
    ui->FenetreInfo->append(error);
        ui->FenetreInfo->append("Requete ok");
}


void SQL_GUI::actionNouveau_Client()
{
    QDialog *dialog = new QDialog(this);
    dialog->show();
}
