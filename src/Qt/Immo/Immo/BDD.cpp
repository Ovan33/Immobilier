#include "BDD.h"

BDD::BDD(QString typeConnection ,QString host, QString database, QString user, QString password)
{
    db = QSqlDatabase::addDatabase(typeConnection);
    db.setHostName(host);
    db.setDatabaseName(database);
    db.setUserName(user);
    db.setPassword(password);
}

bool BDD::isConnectionActive()
{
    return (db.open());

}

bool BDD::isValid()
{
    return (db.isValid());
}

void BDD::close()
{
    db.close();
}
