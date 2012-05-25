#include "widgetbien.h"
#include "ui_widgetbien.h"

WidgetBien::WidgetBien(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetBien)
{
    ui->setupUi(this);
}

WidgetBien::~WidgetBien()
{
    delete ui;
}

void WidgetBien::setPrixVente(int prix)
{
    ui->label_PrixdeVente->setText(QString::number(prix));
}

void WidgetBien::setSurfaceHabitable(int surf)
{
    ui->label_SurfaceHabitable->setText(QString::number(surf));
}

void WidgetBien::setSurfaceJardin(int surf)
{
    ui->label_SurfaceJardin->setText(QString::number(surf));
}

void WidgetBien::setDateMiseVente(QDate date)
{
    ui->dateEdit_dateMiseVente->setDate(date);
}

QDateEdit* WidgetBien::getBoutonDate()
{
    return ui->dateEdit_dateMiseVente;
}

QPushButton * WidgetBien::getBoutonDialogBien()
{
    return ui->pushButton_modifierBien;
}

void WidgetBien::setVille(QString ville)
{
    ui->label_Ville->setText(ville);
}

QPushButton * WidgetBien::getBoutonListeSouhaits()
{
    return ui->pushButton_listeSouhaits;
}

