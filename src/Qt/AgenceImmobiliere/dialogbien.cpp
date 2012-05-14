#include "dialogbien.h"
#include "ui_dialogbien.h"

DialogBien::DialogBien(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogBien)
{
    ui->setupUi(this);
}

DialogBien::~DialogBien()
{
    delete ui;
}
