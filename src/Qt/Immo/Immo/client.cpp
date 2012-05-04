#include "client.h"

//======================================================================
//Initialisation
//======================================================================
Client::Client(int num_c, QString nom, QString adresse, QString tel, Ville ville)
{
           this->m_num_c = num_c;
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
    this->m_adresse = adresse;
}

//======================================================================
//setTelephone
//======================================================================
void Client::setTelephone(QString tel)
{
    this->m_tel = tel;

}
