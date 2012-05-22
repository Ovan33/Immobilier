#include "Souhait.h"

//Souhait::Souhait(QObject *parent) :
//    QObject(parent)
//{
//}

Souhait::Souhait(unsigned int budgetMax, unsigned int surfHabMin, unsigned int surfJardMin, Ville *m_ville)
{
    this->m_budgetMax = budgetMax;
    this->m_surfaceHabitableMinimum = surfHabMin;
    this->m_surfaceJardinMinimum = surfJardMin;
    this->m_listeVilles.append(m_ville);
}

int Souhait::getBudget()
{
    return this->m_budgetMax;
}

int Souhait::getSurface(typeSurf)
{
    if (habitation)
        return this->m_surfaceHabitableMinimum;
    else if (jardin)
        return this->m_surfaceJardinMinimum;
}

//QList<Ville *> getVilles();

void Souhait::setBudget(unsigned int budget)
{
    this->m_budgetMax = budget;
}

void Souhait::setSurface(typeSurf, unsigned int surf)
{
    if (habitation)
        this->m_surfaceHabitableMinimum = surf;
    else if (jardin)
        this->m_surfaceJardinMinimum = surf;
}

//bool modifierVilles();
