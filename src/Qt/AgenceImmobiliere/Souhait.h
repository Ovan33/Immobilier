#ifndef SOUHAIT_H
#define SOUHAIT_H

#include <QObject>
#include "Ville.h"
#include "Client.h"

class Souhait : public QObject
{
//    Q_OBJECT

private:
    unsigned int m_numSouhait;
    unsigned int m_budgetMax;
    unsigned int m_surfaceHabitableMinimum;
    unsigned int m_surfaceJardinMinimum;
    QList<Ville *> m_listeVilles;
    Client *m_client;

public:

//    Souhait(unsigned int budgetMax, unsigned int surfHabMin, unsigned int surfJardMin, Ville *ville, Client *client);
    Souhait(unsigned int numSouhait,unsigned int budgetMax, unsigned int surfHabMin, unsigned int surfJardMin, QList<Ville *> ville, Client *client);

    //  ~Souhait();

    int getNum();
    int getBudget();
    int getSurfaceHabitable();
    int getSurfaceJardin();
    Client *getClient();

    QList<Ville *> getVilles();
    //QList<Ville *> Souhait::getVilles()

    void setNum(unsigned int numSouhait);
    void setBudget(unsigned int budget);
    void setSurfaceHabitable(unsigned int surf);
    void setSurfaceJardin(unsigned int surf);
    void modifierVilles(Ville *ville);

signals:

public slots:

};

#endif // SOUHAIT_H
