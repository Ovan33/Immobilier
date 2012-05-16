#ifndef CONNEXIONSQL_H
#define CONNEXIONSQL_H

#include <QtSql>
#include "Parametre.h"

class BDD
{
public:
    // Constructeur par défaut
    BDD();

    // Construit un objet de type QSqlDatabase
    BDD(QString typeConnection ,QString host, QString database, QString user, QString password);

    // Destructeur
    ~BDD();

    // Renvoie "true" si la connexion est établie. Utilise la méthode QSqlDatabase::open().
    bool isConnectionActive();

    // Renvoie "true" si la connexion est valide. utilise la méthode QSqlDatabase::isValid()
    bool isValid();

    // Ferme la connexion. Utilise QSqlDatabase::close()
    void close();

    // Ouvre la connection
    bool ouvrir();

private:
    QSqlDatabase m_db;
    Parametre *m_settings;

};

#endif // CONNEXIONSQL_H
