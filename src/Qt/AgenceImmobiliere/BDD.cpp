#include "BDD.h"

BDD::BDD(QString typeConnection ,QString host, QString database, QString user, QString password)
{
    db = QSqlDatabase::addDatabase(typeConnection);
    db.setHostName(host);
    db.setDatabaseName(database);
    db.setUserName(user);
    db.setPassword(password);
}

BDD::BDD()
{
    m_settings = new Parametre();
    db = QSqlDatabase::addDatabase(m_settings->getTypeConnection());
    db.setHostName(m_settings->getHost());
    db.setDatabaseName(m_settings->getDataBaseName());
    db.setUserName(m_settings->getUser());
    db.setPassword(m_settings->getPassword());
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
