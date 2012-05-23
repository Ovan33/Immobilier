#include "widgetsouhait.h"
#include "ui_widgetsouhait.h"

widgetSouhait::widgetSouhait(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::widgetSouhait)
{
    ui->setupUi(this);
}

widgetSouhait::~widgetSouhait()
{
    delete ui;
}
