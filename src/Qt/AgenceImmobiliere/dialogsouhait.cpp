#include "dialogsouhait.h"
#include "ui_dialogsouhait.h"

DialogSouhait::DialogSouhait(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogSouhait)
{
    ui->setupUi(this);
}

DialogSouhait::~DialogSouhait()
{
    delete ui;
}
