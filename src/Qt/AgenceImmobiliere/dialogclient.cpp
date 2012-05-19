#include "dialogclient.h"
#include "ui_dialogclient.h"
#include <QMessageBox>

DialogClient::DialogClient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogClient)
{
    ui->setupUi(this);
}

DialogClient::DialogClient(Client *client, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogClient)
{
    ui->setupUi(this);
    changed = false;
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("utf8"));
    this->setWindowTitle("Fiche client - " + client->getNom());
    m_client = client;
    m_menu.setupUi(ui->widget_barreMenu);
    if (m_client->getNom().isEmpty())
        m_menu.label_fenetre->setText("Nouveau client");
    else
        m_menu.label_fenetre->setText(m_client->getNom());
    m_menu.image_fenetre->setPixmap(QPixmap(":/app/client96"));
    m_menu.pushButton_3->setVisible(false);

    ui->lineEdit_Nom->setText(m_client->getNom());
    ui->lineEdit_Adresse->setText(m_client->getAdresse());
    ui->lineEdit_CodePostal->setText(m_client->getVille().getCodePostal());
    ui->lineEdit_Telephone->setText(m_client->getTel());
    ui->comboBox_Villes->addItem(m_client->getVille().getNom());

    // Signaux et Slots
    // Boutons de menu
    QObject::connect(m_menu.pushButton_1,SIGNAL(clicked()),this,SLOT(valider()));
    QObject::connect(m_menu.pushButton_2,SIGNAL(clicked()),this,SLOT(fermer()));
    // changement de valeurs des champs
    QObject::connect(ui->lineEdit_Adresse,SIGNAL(textChanged(QString)),this,SLOT(setEtat(QString)));
    QObject::connect(ui->lineEdit_CodePostal,SIGNAL(textChanged(QString)),this,SLOT(setEtat(QString)));
    QObject::connect(ui->lineEdit_Nom,SIGNAL(textChanged(QString)),this,SLOT(setEtat(QString)));
    QObject::connect(ui->lineEdit_Nom,SIGNAL(textChanged(QString)),this,SLOT(changerLabel(QString)));
    QObject::connect(ui->lineEdit_Telephone,SIGNAL(textChanged(QString)),this,SLOT(setEtat(QString)));
    QObject::connect(ui->comboBox_Villes,SIGNAL(currentIndexChanged(QString)),this,SLOT(setEtat(QString)));
}

DialogClient::~DialogClient()
{
    delete ui;
}

void DialogClient::valider()
{
    // Vérifier les données
    if (!checkData())
    {
        QMessageBox::critical(this,"Données incorrectes","Tous les champs doivent être complétés");
    }
    else
    {   // Si Ok
        // Sauvegarder le client
        if (m_client->sauvegarder())
        {
            this->close();
        }
        else
        {
            QMessageBox::critical(this,"Sauvegarde impossible","Le client n'a pas été sauvegardé. Vérifiez les données entrées et retentez une sauvegarde");
        }
    }
}

bool DialogClient::checkData()
{
    if (ui->lineEdit_Adresse->text().isEmpty()
        || ui->label_CodePostal->text().isEmpty()
        || ui->lineEdit_Nom->text().isEmpty()
        || ui->label_Telephone->text().isEmpty()
        || ui->comboBox_Villes->currentText().isEmpty())
        return false;
    else return true;
}

void DialogClient::fermer()
{
    if (changed)
    {
        int reponse = QMessageBox::warning(this,"Données modifiées","Des données ont été modifiées sans être sauvegardées. Voulez vous vraiment fermer la fenêtre ?",QMessageBox::Yes | QMessageBox::No);
        if (reponse == QMessageBox::Yes)
            this->close();
        else
            this->valider();
    }
    else
    {
        this->close();
    }
}

void DialogClient::setEtat(QString value)
{
    if (!changed)
        changed=true;
}

void DialogClient::changerLabel(QString value)
{
    m_menu.label_fenetre->setText(value);
}
