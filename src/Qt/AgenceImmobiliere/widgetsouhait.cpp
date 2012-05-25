#include "widgetsouhait.h"
#include "ui_widgetsouhait.h"

WidgetSouhait::WidgetSouhait(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetSouhait)
{
    ui->setupUi(this);
}

WidgetSouhait::WidgetSouhait(Souhait *souhait, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetSouhait)
{
    ui->setupUi(this);
    this->m_souhait = souhait;

    m_listeVilles = m_souhait->getVilles();

    for (int i=0; i<m_listeVilles.size(); i++)
    {
        ui->textEdit_Villes->append(m_listeVilles[i]->getNom()+" ("+m_listeVilles[i]->getCodePostal()+")");
    }
}

WidgetSouhait::~WidgetSouhait()
{
    delete ui;
}

void WidgetSouhait::setBudgetMax(unsigned int budget)
{
    ui->label_BudgetMax->setText(QString::number(budget));
}

void WidgetSouhait::setSurfaceHabitableSouhaitee(unsigned int surf)
{
    ui->label_SurfaceHabitableSouhaitee->setText(QString::number(surf));
}

void WidgetSouhait::setSurfaceJardinSouhaitee(unsigned int surf)
{
    ui->label_SurfaceJardinSouhaitee->setText(QString::number(surf));
}

QPushButton *WidgetSouhait::getBoutonDialogSouhait()
{
    return ui->pushButton_modifierSouhait;
}

int WidgetSouhait::getBudgetMax()
{
    return ui->label_BudgetMax->text().toInt();
}

int WidgetSouhait::getSurfaceHabitableSouhaitee()
{
    return ui->label_SurfaceHabitableSouhaitee->text().toInt();
}

int WidgetSouhait::getSurfaceJardinSouhaitee()
{
    return ui->label_SurfaceJardinSouhaitee->text().toInt();
}

QPushButton * WidgetSouhait::getBoutonSupprimer()
{
    return ui->pushButton_supprimerSouhait;
}
