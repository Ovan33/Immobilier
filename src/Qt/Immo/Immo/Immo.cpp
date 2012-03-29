#include "Immo.h"
#include "BDD.h"
#include "Parametre.h"

#include "ui_immo.h"

Immo::Immo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Immo)
{
    ui->setupUi(this);

    // Aller chercher les parametres dans le fichier XML
    Parametre* test = new Parametre();

    // Création de la connexion
    BDD* m_bdd = new BDD(test->getTypeConnection(), test->getHost(), test->getDataBaseName(), test->getUser(), test->getPassword());
    // Test connexion et affichage du test
    if (m_bdd->isValid())
    {
        ui->textEdit->append("Connection valide");
        if (m_bdd->isConnectionActive())
            ui->textEdit->append("Connection etablie");
    }
    m_bdd->close(); // Fermeture connexion
}

Immo::~Immo()
{
    delete ui;
}
