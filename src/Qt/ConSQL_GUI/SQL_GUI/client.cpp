#include "client.h"
#include "ui_client.h"


Client::Client(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Client)
{
    ui->setupUi(this);

//--------------------------------------------------------------------------
    // mode Icone
    // QIcon::Mode = mode;
    // mode = QIcon::On; //Icone est actif
    // mode = QIcon::Off; // Icone n'est pas actif
//--------------------------------------------------------------------------

// Bouton Bien
    ui->BienBouton->setText("");
    ui->BienBouton->setIcon(QIcon("../../../../docs/design/imgs/bien.svg"));
    ui->BienBouton->setIconSize(QSize(80, 80));
    // ajout d'un shortcut =)
    ui->BienBouton->setShortcut(QKeySequence("Ctrl+B"));

// Bouton souhait
    ui->SouhaitBouton->setText("");
    ui->SouhaitBouton->setIcon(QIcon("../../../../docs/design/imgs/souhait.svg"));
    ui->SouhaitBouton->setIconSize(QSize(80, 80));
    // ajout d'un shortcut =)
    ui->SouhaitBouton->setShortcut(QKeySequence("Ctrl+G"));
}

Client::~Client()
{
    delete ui;
}
