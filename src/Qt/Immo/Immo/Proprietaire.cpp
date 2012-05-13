#include "Proprietaire.h"

//======================================================================
//Initialisation
//======================================================================
Proprietaire::Proprietaire(int num, QString nom, QString adresse, QString tel, Ville &ville)
    : Client(num,nom,adresse,tel, ville)
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
    return true;
}

//======================================================================
//supprimerBien
//======================================================================
bool Proprietaire::supprimerBien(Bien bien)
{
    return true;
}

//======================================================================
//modifierBien
//======================================================================
bool Proprietaire::modifierBien(Bien bien)
{
    return true;
}
