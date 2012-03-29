#include "Immo.h"
#include "BDD.h"
#include "Parametre.h"

#include "ui_immo.h"

Immo::Immo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Immo)
{
    ui->setupUi(this);

    Parametre* test = new Parametre();
    QString s = test->getTypeConnection();
    ui->textEdit->append(s);


    BDD* m_bdd = new BDD(test->getTypeConnection(), test->getHost(), test->getDataBaseName(), test->getUser(), test->getPassword());

    if (m_bdd->isValid())
    {
        ui->textEdit->append("Connection valide");
        if (m_bdd->isConnectionActive())
            ui->textEdit->append("Connection etablie");
    }
    m_bdd->close();
}

Immo::~Immo()
{
    delete ui;
}