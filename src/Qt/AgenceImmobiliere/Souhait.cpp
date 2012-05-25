#include "Souhait.h"

Souhait::Souhait(unsigned int numSouhait, unsigned int budgetMax, unsigned int surfHabMin, unsigned int surfJardMin, QList<Ville *> ville, Client *client)
{
    this->m_numSouhait = numSouhait;
    this->m_budgetMax = budgetMax;
    this->m_surfaceHabitableMinimum = surfHabMin;
    this->m_surfaceJardinMinimum = surfJardMin;
    this->m_listeVilles = ville;
    this->m_client = client;
}

Souhait::~Souhait()
{
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

bool Souhait::sauvegarder()
{
    m_db = new BDD();
    bool res;
    if (m_db->ouvrir())
    {
        QSqlQuery requete(m_db->getDb());

        switch(this->getNum())
        {
        case (0):
            //INSERT INTO souhaits(
            //num_s, num_c, budget_max_s, surface_hab_min_s, surface_jardin_min_s)
            //VALUES (?, ?, ?, ?, ?);
            requete.prepare("INSERT INTO souhaits(default,:numClient,:budgetMax,:surfH,:surfJ");
            requete.bindValue(":numClient", this->getClient()->getNum());
            requete.bindValue(":budgetMax", this->getBudget());
            requete.bindValue(":surfH", this->getSurfaceHabitable());
            requete.bindValue(":surfJ", this->getSurfaceJardin());
            break;
        default:
            //UPDATE souhaits
            //   SET num_s=?, num_c=?, budget_max_s=?, surface_hab_min_s=?, surface_jardin_min_s=?
            // WHERE <condition>;
            requete.prepare("UPDATE souhaits SET num_c=:numClient,budget_max_s=:budgetMax,surface_hab_min_s=:surfH,surface_jardin_min_s=:surfJ WHERE num_s=:numSouhait");
            requete.bindValue(":numSouhait", this->getNum());
            requete.bindValue(":numClient", this->getClient()->getNum());
            requete.bindValue(":budgetMax", this->getBudget());
            requete.bindValue(":surfH", this->getSurfaceHabitable());
            requete.bindValue(":surfJ", this->getSurfaceJardin());
        }
        if (requete.exec())
            res = true;
        else
            res = false;
    }
    return res;
    m_db->close();
}

