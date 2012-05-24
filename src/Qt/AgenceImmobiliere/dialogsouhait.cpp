#include "dialogsouhait.h"
#include "ui_dialogsouhait.h"

DialogSouhait::DialogSouhait(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogSouhait)
{
    ui->setupUi(this);
    this->setWindowTitle("Ajouter un nouveau souhait");
   // ui->label_NomClient->setText();
}

DialogSouhait::DialogSouhait(Souhait *souhait, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogSouhait)
{
    ui->setupUi(this);
    m_souhait = souhait;
    this->setWindowTitle("Liste des souhaits");


}

DialogSouhait::~DialogSouhait()
{
    delete ui;
}

