#include "BDD.h"

BDD::BDD(QString host, QString database, QString user, QString password)
{
    db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName(host);
    db.setDatabaseName(database);
    db.setUserName(user);
    db.setPassword(password);
    // test chargement driver sql
    // if (db.isDriverAvailable("QPSQL"))
    //    ui->FenetreInfo->append("Chargement driver ok");
    // test ouverture bdd
    // if (db.open())
    //    ui->FenetreInfo->append("Connexion etablie");
    // else ui->FenetreInfo->append("Connexion impossible !");
}

bool BDD::testConnection()
{
    return (db.open());

}
