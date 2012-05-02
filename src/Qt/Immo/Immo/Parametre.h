#ifndef PARAMETRE_H
#define PARAMETRE_H

#include <qfile.h>
#include <QtXml/qdom.h>
#include<QtXml/QDomDocument>

class Parametre
{
public:
    // Chargement des paramètres de l'application dans un fichier XML
    Parametre();

    QString getTypeConnection();
    QString getHost();
    QString getDataBaseName();
    QString getUser();
    QString getPassword();


private:
    QDomDocument *doc;

    // Paramètres de base de données
    QString typeConnection, host, dataBaseName, user, password;

};

#endif // PARAMETRE_H
