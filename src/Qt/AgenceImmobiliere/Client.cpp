#include "Client.h"

/*
  Constructeur
*/
Client::Client(int num_c, QString nom, QString adresse, QString tel, Ville &ville) :
    QObject()
{
    this->m_num = num_c;
    this->m_nom = nom;
    this->m_adresse = adresse;
    this->m_tel = tel;
    this->m_ville = ville;
}

//======================================================================
//~Destructeur
//======================================================================
Client::~Client ()
{
    // delete m_db;
}

//======================================================================
//setAdresse
//======================================================================
void Client::setAdresse(QString adr)
{
    // this->m_adresse = adresse;
    this->m_adresse = adr;
}

//======================================================================
//setTelephone
//======================================================================
void Client::setTelephone(QString tel)
{
    this->m_tel = tel;
}

QString Client::getAdresse()
{
    return this->m_adresse;
}

QString Client::getNom()
{
    return this->m_nom;
}

QString Client::getTel()
{
    return this->m_tel;
}

Ville& Client::getVille()
{
    return this->m_ville;
}

bool Client::sauvegarder()
{
    QString requete;
    bool res;
    switch(this->m_num)
    {
    case (0):
        requete = "INSERT INTO clients VALUES(default,";
        requete += this->getVille().getNum();
        requete += ",NULL,'";
        requete += this->getNom() + "','" + this->getAdresse() + "','" + this->getTel();
        requete += "')";
        break;
    default:
        requete = "update clients ";
        requete += "set num_a=" + this->m_num_a;
        requete += ",";
        requete += "set nom_c=" + this->m_nom +",";
        requete += "set adresse_c=" + this->m_adresse +",";
        requete += "set tel_c=" + this->m_tel +",";
        requete += "set num_v=" + this->m_ville.getNum();
        requete += " ";
        requete += "where num_c=" + this->m_num;
    }
    m_db = new BDD();
    if (m_db->ouvrir())
    {
        QSqlQuery sauvegarde;
        if (sauvegarde.exec(requete))
            res = true;
        else
            res = false;
    }
    m_db->close();
    return res;
}

