#include "dialogrecherchebiens.h"
#include "ui_dialogrecherchebiens.h"

DialogRechercheBiens::DialogRechercheBiens(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogRechercheBiens)
{
    ui->setupUi(this);
}

DialogRechercheBiens::~DialogRechercheBiens()
{
    delete ui;
}
