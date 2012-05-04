#ifndef PROPRIETAIRE_H
#define PROPRIETAIRE_H

#include <client.h>

class Proprietaire : public Client
{

public:

    Proprietaire(QString nom, QString adresse, QString tel, Ville ville);
    ~Proprietaire();
    bool ajouterBien (Bien bien);
    bool supprimerBien (Bien bien);
    bool modifierBien (Bien bien);

private:

    //Liste de biens par proprietaire
    QList<Bien> m_listeBiens;

};

#endif // PROPRIETAIRE_H
