#include "proprietaire.h"

//======================================================================
//Initialisation
//======================================================================
Proprietaire::Proprietaire(QString nom, QString adresse, QString tel, Ville ville)
{


}

//======================================================================
//Destructeur
//======================================================================
Proprietaire::~Proprietaire()
{

}

//======================================================================
//ajouterBien
//======================================================================
bool Proprietaire::ajouterBien(Bien bien)
{
    return bienAjoute;
}

//======================================================================
//supprimerBien
//======================================================================
bool Proprietaire::supprimerBien(Bien bien)
{
    return bienSupprimer;
}

//======================================================================
//modifierBien
//======================================================================
bool Proprietaire::modifierBien(Bien bien)
{
    return bienModifie;
}
