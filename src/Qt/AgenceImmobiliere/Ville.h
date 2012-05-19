#ifndef VILLE_H
#define VILLE_H

#include "BDD.h"
#include <QObject>

class Ville : public QObject
{
    Q_OBJECT
private:
    unsigned int m_num;
    QString m_nom;
    QString m_codePostal;

    Ville retrieveFromDB(QString nom, QString codePostal);

public:
    explicit Ville(QObject *parent = 0);
    Ville(QString nom, QString codePostal);

    // ~Ville;

    QString getNom();
    QString getCodePostal();
    int getNum();
    static bool isExisting(QString nom, QString codePostal);
    void modifierVille(QString nom, QString codePostal);
    void operator=(const Ville &ville);

signals:

public slots:

};

#endif // VILLE_H
