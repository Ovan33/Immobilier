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
    QString s = test->getHost();
    ui->textEdit->append(s);

    BDD* m_bdd = new BDD(test->getHost(), test->getDataBaseName(), test->getUser(), test->getPassword());
    if (m_bdd->testConnection())
        ui->textEdit->append("Connection établie");
}

Immo::~Immo()
{
    delete ui;
}
