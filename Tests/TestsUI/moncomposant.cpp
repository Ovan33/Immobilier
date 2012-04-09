#include "moncomposant.h"
#include "ui_moncomposant.h"

MonComposant::MonComposant(QWidget *parent, QString nom, QString adresse, QString tel, Qtring ville) :
    QWidget(parent),
    ui(new Ui::MonComposant)
{
    ui->setupUi(this);
    ui->label_NomClient->setText(nom);
    ui->label_AdresseClient->setText(adresse);
    ui->label_TelephoneClient->setText(tel);
    ui->label_CodePostalVilleClient->setText(ville);
}

MonComposant::~MonComposant()
{
    delete ui;
}
