#include "Client.h"

/*
  Constructeur
*/
//Client::Client(int num_c, QString nom, QString adresse, QString tel, Ville &ville) :
Client::Client(int num_c, QString nom, QString adresse, QString tel, Ville *ville, int numA) :
    QObject()
{
    this->m_num = num_c;
    this->m_nom = nom;
    this->m_adresse = adresse;
    this->m_tel = tel;
    this->m_ville = ville;
    this->m_num_a = numA;
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

int Client::getNumA()
{
    return this->m_num_a;
}

QString Client::getNom()
{
    return this->m_nom;
}

QString Client::getTel()
{
    return this->m_tel;
}

Ville* Client::getVille()
{
    return this->m_ville;
}

int Client::getNum()
{
    return this->m_num;
}

void Client::setNumA(int numA)
{
    this->m_num_a = numA;
}

bool Client::sauvegarder()
{
    QString requete;
    bool res;

    // debug infos
    qDebug()    << "NumA : " << this->m_num_a << endl
                << "Nom : " << this->m_nom << endl
                << "NumC : " << this->m_num << endl
                << "Adr : "<< this->m_adresse << endl
                << "tel : " << this->m_tel << endl
                << "NumVille : " << this->m_ville->getNum();
    // debug infos

    switch(this->m_num)
    {
    case (0):
        requete = "INSERT INTO clients VALUES(default,";
        requete += QString::number(this->getVille()->getNum());
        requete += ",NULL,'";
        requete += this->getNom() + "','" + this->getAdresse() + "','" + this->getTel();
        requete += "')";
        break;
    default:
        requete = "update clients ";
        requete += "set num_a=";
        requete += QString::number(this->m_num_a);
        requete += ",";
        requete += "nom_c='";
        requete += this->m_nom;
        requete += "',";
        requete += "adresse_c='";
        requete += this->m_adresse;
        requete += "',";
        requete += "tel_c='";
        requete += this->m_tel;
        requete += "',";
        requete += "num_v=";
        requete += QString::number(this->getVille()->getNum());
        requete += " ";
        requete += "where num_c=";
        requete += QString::number(this->m_num);
    }
    // Debug Infos
    qDebug() << requete;
    // Fin
    m_db = new BDD();
    if (m_db->ouvrir())
    {
        QSqlQuery sauvegarde;
        qDebug() << requete;
        if (sauvegarde.exec(requete))
            res = true;
        else
            res = false;
    }
    m_db->close();
    return res;
}

void Client::setNom(QString nom)
{
    this->m_nom=nom;
}

void Client::setVille(Ville *ville)
{
    this->m_ville = ville;
}

