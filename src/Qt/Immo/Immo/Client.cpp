#include "Client.h"

/*
  Constructeur
*/
Client::Client(int num_c, QString nom, QString adresse, QString tel, Ville &ville)
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
