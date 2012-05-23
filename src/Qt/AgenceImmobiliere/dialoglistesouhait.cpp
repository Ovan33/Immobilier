#include "dialoglistesouhait.h"
#include "ui_dialoglistesouhait.h"

DialogListeSouhait::DialogListeSouhait(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogListeSouhait)
{
    ui->setupUi(this);
}

DialogListeSouhait::~DialogListeSouhait()
{
    delete ui;
}
