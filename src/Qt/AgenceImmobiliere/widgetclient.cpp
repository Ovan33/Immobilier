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

void WidgetClient::setNom(QString nom)
{
    ui->label_Nom->setText(nom);
}

void WidgetClient::setAdresse(QString adresse)
{
    ui->label_Adresse->setText(adresse);
}

void WidgetClient::setTelephone(QString tel)
{
    ui->label_Telephone->setText(tel);
}

void WidgetClient::setVille(QString ville)
{
    ui->label_Ville->setText(ville);
}

void WidgetClient::setCodePostal(QString cp)
{
    ui->label_CodePostal->setText(cp);
}
