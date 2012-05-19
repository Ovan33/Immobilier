#include "Bien.h"

Bien::Bien(QObject *parent) :
    QObject(parent)
{
}

Bien::Bien(unsigned int prix, QDate date, unsigned int surfHab, unsigned int surfJar, Ville ville)
{
    this->m_prixVente = prix;
    this->m_dateMiseVente = date;
    this->m_surfaceHabitable = surfHab;
    this->m_surfaceJardin = surfJar;
    this->m_ville = ville;
}

void Bien::setPrix(unsigned int prix)
{
    this->m_prixVente = prix;
}

void Bien::setDate(QDate date)
{
    this->m_dateMiseVente = date;
}

void Bien::setSurf(typeSurf, unsigned int surf)
{
    if (habitation)
        this->m_surfaceHabitable = surf;
    else if (jardin)
        this->m_surfaceJardin = surf;

}

int Bien::getPrix()
{
    return this->m_prixVente;

}

int Bien::getSurf(typeSurf)
{
    if (habitation)
        return this->m_surfaceHabitable;
    else if (jardin)
        return this->m_surfaceJardin;
}

QDate Bien::getDate()
{
    return this->m_dateMiseVente;
}
