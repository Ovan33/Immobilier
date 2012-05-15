#include "dialogaccueil.h"
#include "ui_dialogaccueil.h"

DialogAccueil::DialogAccueil(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAccueil)
{
    ui->setupUi(this);
    m_menu.setupUi(ui->widget_barreMenu);
    m_menu.label_fenetre->setText("Accueil");
}

DialogAccueil::~DialogAccueil()
{
    delete ui;
}
