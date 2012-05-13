#include "dialogclient.h"
#include "ui_dialogclient.h"

DialogClient::DialogClient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogClient)
{
    ui->setupUi(this);
}

DialogClient::~DialogClient()
{
    delete ui;
}
