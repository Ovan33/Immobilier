#include "Immo.h"
#include "BDD.h"
#include "Parametre.h"
#include "Ville.h"
#include "Client.h"
#include <QDebug>

#include "ui_immo.h"
#include "dialogclient.h"

Immo::Immo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Immo)
{
    ui->setupUi(this);
    /* Parametre* test = new Parametre();
    Ville cado("Cadaujac","33140");

    Client client(1, "NomClient", "AdresseClient", "TelClient", cado);
    Client *cl = &client;
    // cl = &client;
    DialogClient dc(cl);
    // dc.setClient(cl);
    dc.setParent(this);

    dc.open();
    // ui->textEdit->append(cado.getCodePostal());
    // ui->textEdit->append(cado.getNom());

    /* Tests Base de données
    BDD* m_bdd = new BDD(test->getTypeConnection(), test->getHost(), test->getDataBaseName(), test->getUser(), test->getPassword());
    // Test connexion et affichage du test
    if (m_bdd->isValid())
    {
        ui->textEdit->append("Connection valide");
        if (m_bdd->isConnectionActive())
        {
            ui->textEdit->append("Connection etablie");
        }


        if (Ville::isExisting("Cadaujac","33140"))
        ui->textEdit->append("Trouvée");
    else
        ui->textEdit->append("pas trouvée");
    }    
    m_bdd->close(); // Fermeture connexion
    */
}

Immo::~Immo()
{
    delete ui;
}
