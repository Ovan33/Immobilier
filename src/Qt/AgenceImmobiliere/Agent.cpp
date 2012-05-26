#include "Agent.h"

Agent::Agent(int num, QString nom)
{
    this->m_num = num;
    this->m_nom = nom;
}

void Agent::setNom(QString nom)
{
    this->m_nom = nom;
}

QString Agent::getNom()
{
    return this->m_nom;
}

void Agent::setNum(int num)
{
    this->m_num = num;
}

int Agent::getNum()
{
    return this->m_num;
}

bool Agent::sauvegarder()
{
    m_db = new BDD();
    bool res;
    if (m_db->ouvrir())
    {
        QSqlQuery requete(m_db->getDb());
        switch(this->m_num)
        {
        // Nouvel Agent
        case(0):
            requete.prepare("INSERT INTO agents VALUES(defaut,:nomAgent)");
            requete.bindValue(":nomAgent", this->m_nom);
            break;
        // Agent existant (modification du nom seulement)
        default:
            requete.prepare("UPDATE agents SET num_a=:numAgent, prenom_a=:nomAgent WHERE num-a=:numAgent");
            requete.bindValue(":numAgent", this->m_num);
            requete.bindValue(":nomAgent", this->m_nom);
        }
        if (requete.exec())
            res = true;
        else
            res = false;

    }
    m_db->close();
    return res;
}
