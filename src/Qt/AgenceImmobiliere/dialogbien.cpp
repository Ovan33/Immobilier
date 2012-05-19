#include "dialogbien.h"
#include "ui_dialogbien.h"

DialogBien::DialogBien(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogBien)
{
    ui->setupUi(this);
    this->setWindowTitle("Gestion de biens immobiliers - Bien");

    // Création de la barre de menu
    m_menu.setupUi(ui->widget_barreMenu);
    m_menu.label_fenetre->setText("Bien");
    m_menu.image_fenetre->setPixmap(QPixmap(":/app/bien96"));


    m_menu.pushButton_1->setToolTip("Valider");
    m_menu.pushButton_2->setToolTip("Annuler");
    m_menu.pushButton_3->setToolTip("Quitter l'application");

    // SIGNAUX et SLOTS
//    QObject::connect(m_menu.pushButton_1, SIGNAL(clicked()), this, SLOT(maMethode()));
    QObject::connect(m_menu.pushButton_2, SIGNAL(clicked()), this, SLOT(close()));
    QObject::connect(m_menu.pushButton_3, SIGNAL(clicked()), qApp, SLOT(quit()));



}

DialogBien::~DialogBien()
{
    delete ui;
}

