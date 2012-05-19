#ifndef BIEN_H
#define BIEN_H

#include <QObject>

#include <QDate>
#include "Ville.h"
#include "Client.h"


class Bien : public QObject
{
 //   Q_OBJECT

private:
    unsigned int m_num;
    unsigned int m_prixVente;
    QDate m_dateMiseVente;
    unsigned int m_surfaceHabitable;
    unsigned int m_surfaceJardin;
    Ville m_ville;
    Client *m_client;

public:
    enum typeSurf {habitation,jardin};

  //  explicit Bien(QObject *parent = 0);
    Bien(unsigned int prix, QDate date, unsigned int surfHab, unsigned int surfJar, Ville ville, Client *client);

    void setPrix(unsigned int prix);
    void setDate(QDate date);
    void setSurf(typeSurf, unsigned int surf);

    int getPrix();
    int getSurf(typeSurf);
    QDate getDate();

signals:

public slots:

};

#endif // BIEN_H
