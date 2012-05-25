#include "Souhait.h"

//Souhait::Souhait(QObject *parent) :
//    QObject(parent)
//{
//}

Souhait::Souhait(unsigned int numSouhait, unsigned int budgetMax, unsigned int surfHabMin, unsigned int surfJardMin, QList<Ville *> ville, Client *client)
{
    this->m_numSouhait = numSouhait;
    this->m_budgetMax = budgetMax;
    this->m_surfaceHabitableMinimum = surfHabMin;
    this->m_surfaceJardinMinimum = surfJardMin;
    this->m_listeVilles = ville;
    this->m_client = client;
}

int Souhait::getNum()
{
    return this->m_numSouhait;
}

int Souhait::getBudget()
{
    return this->m_budgetMax;
}

int Souhait::getSurfaceHabitable()
{
    return this->m_surfaceHabitableMinimum;
}

int Souhait::getSurfaceJardin()
{
    return this->m_surfaceJardinMinimum;
}

Client* Souhait::getClient()
{
    return this->m_client;
}

QList<Ville *> Souhait::getVilles()
{
    return this->m_listeVilles;
}

void Souhait::setNum(unsigned int numSouhait)
{
    this->m_numSouhait = numSouhait;
}

void Souhait::setBudget(unsigned int budget)
{
    this->m_budgetMax = budget;
}

void Souhait::setSurfaceHabitable(unsigned int surf)
{
    this->m_surfaceHabitableMinimum = surf;
}

void Souhait::setSurfaceJardin(unsigned int surf)
{
    this->m_surfaceJardinMinimum = surf;
}

void Souhait::modifierVilles(Ville *ville)
{
    this->m_listeVilles.append(ville);
}
