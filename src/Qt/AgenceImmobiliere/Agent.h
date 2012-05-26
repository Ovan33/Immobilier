#ifndef AGENT_H
#define AGENT_H

#include <QString>
#include <BDD.h>

class Agent
{
public:
    Agent(int num, QString nom);

    void setNom(QString nom);
    QString getNom();

    void setNum(int num);
    int getNum();

    bool sauvegarder();

private:
    unsigned int m_num;
    QString m_nom;
    BDD *m_db;
};

#endif // AGENT_H
