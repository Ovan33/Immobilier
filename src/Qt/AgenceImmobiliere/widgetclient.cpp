#include "widgetclient.h"
#include "ui_widgetclient.h"

WidgetClient::WidgetClient(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetClient)
{
    ui->setupUi(this);
}

WidgetClient::~WidgetClient()
{
    delete ui;
}
