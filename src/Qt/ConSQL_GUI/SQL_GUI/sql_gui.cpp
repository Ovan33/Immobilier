#include "sql_gui.h"
#include "ui_sql_gui.h"



SQL_GUI::SQL_GUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SQL_GUI)
{
    ui->setupUi(this);
    ui->FenetreInfo->append("Connexion a la base de donnees...");
    ConnexionBDD();
   // RequeteVille();
    RemplissageTV();
}

SQL_GUI::~SQL_GUI()
{
    delete ui;
}

void SQL_GUI::ConnexionBDD()
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
void SQL_GUI::RequeteVille()
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
void SQL_GUI::RemplissageTV()
{
    QSqlTableModel *model = new QSqlTableModel(this, db);
    model->setTable("villes");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();
    model->removeColumn(0); // don't show the ID
    model->setHeaderData(0, Qt::Horizontal, tr("Nom"));
    model->setHeaderData(1, Qt::Horizontal, tr("CP"));
    ui->tableView->setModel(model);


}
