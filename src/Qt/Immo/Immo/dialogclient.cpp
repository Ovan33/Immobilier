#include "dialogclient.h"
#include "ui_dialogclient.h"

// DialogClient::DialogClient(Client *client, QWidget *parent) :
    // QDialog(parent),
DialogClient::DialogClient(Client *client) :
// DialogClient::DialogClient() :
   ui(new Ui::DialogClient)
{
    this->m_client = client;
    ui->setupUi(this);
    ui->lineEdit_nom->setText(m_client->getNom());
    ui->lineEdit_adresse->setText(m_client->getAdresse());
    ui->lineEdit_codePostal->setText(m_client->getVille().getCodePostal());
    ui->lineEdit_ville->setText(m_client->getVille().getNom());
    ui->lineEdit_telephone->setText(m_client->getTel());
}

void DialogClient::setClient(Client *client)
{
    this->m_client = client;
    ui->lineEdit_nom->setText(m_client->getNom());
    ui->lineEdit_adresse->setText(m_client->getAdresse());
    ui->lineEdit_codePostal->setText(m_client->getVille().getCodePostal());
    ui->lineEdit_ville->setText(m_client->getVille().getNom());
    ui->lineEdit_telephone->setText(m_client->getTel());
}

DialogClient::~DialogClient()
{
    delete ui;
}
