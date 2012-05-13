#include "dialogaccueil.h"
#include "ui_dialogaccueil.h"

DialogAccueil::DialogAccueil(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAccueil)
{
    ui->setupUi(this);
}

DialogAccueil::~DialogAccueil()
{
    delete ui;
}
