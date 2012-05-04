#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QString>
#include "Ville.h"

class Client : public QObject
{

public:

    Client (int num, QString nom,QString adresse,QString tel,Ville ville);
    ~Client ();
    void setAdresse (QString adr);
    void setTelephone (QString tel);

private:
    /*
    unsigned int m_num_c = num_c;
    QString m_nom = nom;
    QString m_adresse = adresse;
    QString m_tel = tel;
    Ville m_ville = ville;
    */
    unsigned int m_num;
    QString m_nom;
    QString m_adresse;
    QString m_tel;
    Ville m_ville;

};

#endif // CLIENT_H
