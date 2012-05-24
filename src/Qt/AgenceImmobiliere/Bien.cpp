#include "Bien.h"

//Bien::Bien(QObject *parent) :
//    QObject(parent)
//{
//}

Bien::Bien(unsigned int prix, QDate &date, unsigned int surfHab, unsigned int surfJar, Ville *ville, Client *client)
{
    this->m_prixVente = prix;
    this->m_dateMiseVente = date;
    this->m_surfaceHabitable = surfHab;
    this->m_surfaceJardin = surfJar;
    this->m_ville = ville;
    this->m_client = client;
}

Bien::Bien(unsigned int numB, unsigned int prix, QDate &date, unsigned int surfHab, unsigned int surfJar, Ville *ville, Client *client)
{
    this->m_num = numB;
    this->m_prixVente = prix;
    this->m_dateMiseVente = date;
    this->m_surfaceHabitable = surfHab;
    this->m_surfaceJardin = surfJar;
    this->m_ville = ville;
    this->m_client = client;
}

void Bien::setPrix(unsigned int prix)
{
    this->m_prixVente = prix;
}

void Bien::setDate(QDate date)
{
    this->m_dateMiseVente = date;
}

int Bien::getPrix()
{
    return this->m_prixVente;
}

QDate Bien::getDate()
{
    return this->m_dateMiseVente;
}

Client* Bien::getClient()
{
    return this->m_client;
}

Ville* Bien::getVille()
{
    return this->m_ville;
}

int Bien::getSurfHabitable()
{
    return this->m_surfaceHabitable;
}

int Bien::getSurfJardin()
{
    return this->m_surfaceJardin;
}

void Bien::setSurfHabitable(int surf)
{
    this->m_surfaceHabitable = surf;
}

void Bien::setSurfJardin(int surf)
{
    this->m_surfaceJardin = surf;
}
