#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QString>
#include <Ville.h>
#include <BDD.h>

class Client : public QObject
{

public:
    //Client (int num, QString nom,QString adresse,QString tel, Ville &ville);
    Client (int num, QString nom,QString adresse,QString tel, Ville *ville);
    ~Client ();
    void setAdresse (QString adr);
    void setTelephone (QString tel);
    int getNum();
    QString getNom();
    QString getAdresse();
    QString getTel();
    Ville* getVille();
    bool sauvegarder();

private:
    unsigned int m_num;
    unsigned int m_num_a;
    QString m_nom;
    QString m_adresse;
    QString m_tel;
    Ville *m_ville;
    BDD *m_db;
};

#endif // CLIENT_H
