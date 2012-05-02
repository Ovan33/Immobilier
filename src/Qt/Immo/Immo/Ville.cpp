#include "Ville.h"

/*
Ville::Ville(QObject *parent) :
    QObject(parent)
{
}
*/

Ville::Ville(QString nom, QString codePostal)
{
    this->m_nom = nom;
    this->m_codePostal = codePostal;
    this->m_num = 0;
}

Ville::~Ville()
{
}

QString Ville::getNom()
{
    return this->m_nom;
}

QString Ville::getCodePostal()
{
    return this->m_codePostal;
}

bool Ville::isExisting(QString nom, QString codePostal)
{
    Ville ville = retrieveFromDB(nom, codePostal);
    return (this->nom == ville.getNom() && this->codePostal == ville.getCodePostal());
}

bool Ville::modifierVille(QString nom, QString codePostal)
{
    this->nom = nom;
    this->codePostal = codePostal;
    return true;
}

Ville Ville::retrieveFromDB(QString nom, QString codePostal, BDD connexion)
{
    Ville ville;
    QSqlQuery query;
    QString q_nom;
    QString q_codePostal;
    query.prepare("SELECT * from VILLES where NOM_V = :q_nom AND CODE_POSTAL_V = :q_codePostal");
    query.bindValue(":q_nom", q_nom);
    query.bindValue(":q_codePostal", q_codePostal);

    if (query.exec())
    {
        while (query.next())
        {
            ville.m_nom = query.value(1).toString();
            ville.m_codePostal = query.value(2).toString();
        }
    }
    return ville;
}
