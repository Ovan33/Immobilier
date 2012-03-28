#ifndef PARAMETRE_H
#define PARAMETRE_H

#include <qfile.h>
#include <QtXml/qdom.h>
#include<QtXml/QDomDocument>

class Parametre
{
public:
    Parametre();

    QString getHost();
    QString getDataBaseName();
    QString getUser();
    QString getPassword();


private:

    QDomDocument *doc;
    QString host, dataBaseName, user, password;

};

#endif // PARAMETRE_H
