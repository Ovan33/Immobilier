#ifndef SOUHAIT_H
#define SOUHAIT_H

#include <QObject>
#include "Ville.h"
#include "Client.h"

class Souhait : public QObject
{
//    Q_OBJECT

private:
    unsigned int m_num;
    unsigned int m_budgetMax;
    unsigned int m_surfaceHabitableMinimum;
    unsigned int m_surfaceJardinMinimum;
    QList<Ville *> m_listeVilles;
    Client *m_client;

public:
   // enum typeSurf {habitation,jardin};

   // explicit Souhait(QObject *parent = 0);
    Souhait(unsigned int budgetMax, unsigned int surfHabMin, unsigned int surfJardMin, Ville *ville, Client *client);
  //  ~Souhait();

    int getBudget();
    int getSurfaceHabitable();
    int getSurfaceJardin();
    Client *getClient();
    QList<Ville *> getVilles();

    void setBudget(unsigned int budget);
    void setSurfaceHabitable(unsigned int surf);
    void setSurfaceJardin(unsigned int surf);
    bool modifierVilles();

signals:

public slots:

};

#endif // SOUHAIT_H
