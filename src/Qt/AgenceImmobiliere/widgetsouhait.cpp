#include "widgetsouhait.h"
#include "ui_widgetsouhait.h"

WidgetSouhait::WidgetSouhait(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetSouhait)
{
    ui->setupUi(this);
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
