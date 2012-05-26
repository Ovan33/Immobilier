#include "widgetagent.h"
#include "ui_widgetagent.h"

WidgetAgent::WidgetAgent(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetAgent)
{
    ui->setupUi(this);
}

WidgetAgent::~WidgetAgent()
{
    delete ui;
}

void WidgetAgent::setNom(QString nom)
{
    ui->label_Nom->setText(nom);
}
