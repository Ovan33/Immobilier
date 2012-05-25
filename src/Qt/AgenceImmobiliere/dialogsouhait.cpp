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

    m_listeVilles = m_souhait->getVilles();
    for (int i=0; i<m_listeVilles.size(); i++)
    {
        ui->textEdit_Villes->append(m_listeVilles[i]->getNom()+" ("+m_listeVilles[i]->getCodePostal()+")");
    }


}

DialogSouhait::~DialogSouhait()
{
    delete ui;
}

