#ifndef ACHETEUR_H
#define ACHETEUR_H


#include <QList>
#include <client.h>

class Acheteur:public Client

{

public:

    Acheteur();
    ~Acheteur ();
    bool ajouterSouhait (Souhait souhait);
    bool supprimerSouhait (Souhait souhait);
    bool modifierSouhait (Souhait souhait);
    void afficherSouhaits ();

 private:
    //liste de souhaits par acheteur
    QList<Souhait> m_listeSouhaits;
};

#endif // ACHETEUR_H
