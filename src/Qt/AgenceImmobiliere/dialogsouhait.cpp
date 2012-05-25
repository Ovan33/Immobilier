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
    ui->label_NomClient->setText((m_souhait->getClient())->getNom());
    ui->lineEdit_BudgetMax->setText(QString::number(m_souhait->getBudget()));
    ui->lineEdit_SurfHabMin->setText(QString::number(m_souhait->getSurfaceHabitable()));
    ui->lineEdit_SurJardMin->setText(QString::number(m_souhait->getSurfaceJardin()));
//    ui->lineEdit_CodePostal_Souhait->setText(m_souhait->);


}

DialogSouhait::~DialogSouhait()
{
    delete ui;
}

