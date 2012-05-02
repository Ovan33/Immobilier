#ifndef VILLE_H
#define VILLE_H

#include "BDD.h"
#include <QObject>

class Ville : public QObject
{
    Q_OBJECT
private:
    unsigned int m_numVille;
    QString m_nom;
    QString m_codePostal;

    Ville retrieveFromDB(QString nom, QString codePostal, BDD connexion);

public:
    // explicit Ville(QObject *parent = 0);
    Ville(QString nom, QString codePostal);
    ~Ville;

    QString getNom();
    QString getCodePostal();
    bool isExisting();
    void modifierVille(QString nom, QString codePostal);

signals:

public slots:

};

#endif // VILLE_H
