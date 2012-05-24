#include "dialogbien.h"
#include "ui_dialogbien.h"
#include <QMessageBox>

DialogBien::DialogBien(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogBien)
{
    ui->setupUi(this);
}

DialogBien::DialogBien(Bien *bien, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogBien)
{
    ui->setupUi(this);
    m_bien = bien;
    this->setWindowTitle("Gestion de biens immobiliers");
    // Création de la barre de menu
    m_menu.setupUi(ui->widget_barreMenu);
    m_menu.label_fenetre->setText("Bien");
    m_menu.image_fenetre->setPixmap(QPixmap(":/app/bien96"));
    m_menu.pushButton_1->setToolTip("Valider");
    m_menu.pushButton_2->setToolTip("Annuler");
    m_menu.pushButton_3->setToolTip("Quitter l'application");
    ui->label_NomClient->setText(bien->getClient()->getNom());
    ui->spinBox_prixVente->setValue(m_bien->getPrix());
    ui->lineEdit_CodePostal->setText(m_bien->getVille()->getCodePostal());
    ui->spinBox_SurfaceHabitable->setValue(m_bien->getSurfHabitable());
    ui->spinBox_SurfaceJardin->setValue(m_bien->getSurfJardin());
    ui->dateEdit_DateMiseVente->setDate(m_bien->getDate());
    ui->comboBox_Ville->setCurrentIndex(0);
    ui->button_ModifierBien->setVisible(false);
    ui->button_Supprimer->setVisible(false);
    ui->button_ChercherVilles->setEnabled(false);
    ui->button_ChercherVilles->setToolTip("Rechercher les villes correspondant au code postal");
    // SIGNAUX et SLOTS
    QObject::connect(m_menu.pushButton_3, SIGNAL(clicked()), qApp, SLOT(quit()));
    QObject::connect(m_menu.pushButton_1,SIGNAL(clicked()),this,SLOT(close()));
    QObject::connect(ui->lineEdit_CodePostal,SIGNAL(textChanged(QString)),this,SLOT(enableRechercherVilles(QString)));
}

DialogBien::~DialogBien()
{
    delete m_db;
    delete ui;
}

void DialogBien::chercherVilles()
{
    if (ui->lineEdit_CodePostal->text().isEmpty())
        QMessageBox::information(this,"Données incorrectes","Merci de renseigner le code postal");
    else
    {
        QString requete = "select * from VILLES where CODE_POSTAL_V='" + ui->lineEdit_CodePostal->text();
        requete += "' order by nom_v";
        qDebug() << requete;
        // pour chaque res, création d'une ville
        m_db = new BDD();
        if (m_db->ouvrir())
        {
            QSqlQuery resultat;
            if (resultat.exec(requete))
            {
                if (resultat.size() < 1)
                    QMessageBox::information(this,"Recherche client", "Aucune ville ne correspond à ce code postal");
                else
                {
                    while (resultat.next())
                    {
                        Ville *ville = new Ville(resultat.value(0).toInt(), resultat.value(1).toString(), resultat.value(2).toString());
                        m_listeVilles.append(ville);
                        qDebug() << ville->getNom();
                        ui->comboBox_Ville->addItem(ville->getNom());
                    }
                }
            }
        }
        m_db->close();
    }
}

void DialogBien::enableRechercherVilles(QString)
{
    ui->button_ChercherVilles->setEnabled(true);
}



