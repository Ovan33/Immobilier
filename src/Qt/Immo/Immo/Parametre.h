#ifndef PARAMETRE_H
#define PARAMETRE_H

#include <qfile.h>
#include <QtXml/qdom.h>
#include<QtXml/QDomDocument>

class Parametre
{
public:
    //Permet d'aller charger des paramètres (ici de connection SQL) dans un fichier XML
    Parametre();

    QString getTypeConnection();
    QString getHost();
    QString getDataBaseName();
    QString getUser();
    QString getPassword();


private:

    QDomDocument *doc;
    QString typeConnection, host, dataBaseName, user, password;

};

#endif // PARAMETRE_H
