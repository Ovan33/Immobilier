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
    this->changed = false;
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("utf8"));
    this->setWindowTitle("Gestion de biens immobiliers");
    // Création de la barre de menu
    m_menu.setupUi(ui->widget_barreMenu);
    m_menu.label_fenetre->setText("Bien");
    m_menu.image_fenetre->setPixmap(QPixmap(":/app/bien96"));
    m_menu.pushButton_1->setToolTip("Valider");
    m_menu.pushButton_2->setToolTip("Annuler");
    m_menu.pushButton_3->setVisible(false);
    ui->label_NomClient->setText(bien->getClient()->getNom());
    ui->spinBox_prixVente->setValue(m_bien->getPrix());
    ui->lineEdit_CodePostal->setText(m_bien->getVille()->getCodePostal());
    ui->spinBox_SurfaceHabitable->setValue(m_bien->getSurfHabitable());
    ui->spinBox_SurfaceJardin->setValue(m_bien->getSurfJardin());
    ui->dateEdit_DateMiseVente->setDate(m_bien->getDate());
    //ui->comboBox_Ville->setCurrentIndex(0);
    //ui->comboBox_Ville->setItemText(0);
    ui->comboBox_Ville->addItem(m_bien->getVille()->getNom());
    ui->button_ModifierBien->setVisible(false);
    ui->button_Supprimer->setVisible(false);
    ui->button_ChercherVilles->setEnabled(false);
    ui->button_ChercherVilles->setToolTip("Rechercher les villes correspondant au code postal");
    // SIGNAUX et SLOTS
    // QObject::connect(m_menu.pushButton_2,SIGNAL(clicked()),this,SLOT(close()));
    QObject::connect(ui->lineEdit_CodePostal,SIGNAL(textChanged(QString)),this,SLOT(enableRechercherVilles(QString)));
    QObject::connect(ui->lineEdit_CodePostal,SIGNAL(textChanged(QString)),this,SLOT(setEtat(QString)));
    QObject::connect(ui->spinBox_prixVente,SIGNAL(valueChanged(QString)),this,SLOT(setEtat(QString)));
    QObject::connect(ui->spinBox_SurfaceHabitable,SIGNAL(valueChanged(QString)),this,SLOT(setEtat(QString)));
    QObject::connect(ui->spinBox_SurfaceJardin,SIGNAL(valueChanged(QString)),this,SLOT(setEtat(QString)));
    QObject::connect(ui->dateEdit_DateMiseVente,SIGNAL(dateChanged(QDate)),this,SLOT(setEtat(QDate)));
    QObject::connect(ui->button_ChercherVilles,SIGNAL(clicked()),this,SLOT(chercherVilles()));
    QObject::connect(m_menu.pushButton_1,SIGNAL(clicked()),this,SLOT(valider()));
    QObject::connect(m_menu.pushButton_2,SIGNAL(clicked()),this,SLOT(fermer()));
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

void DialogBien::setEtat(QString)
{
    if (!changed)
        changed=true;
}

void DialogBien::setEtat(QDate)
{
    if (!changed)
        changed=true;
}

void DialogBien::fermer()
{
    if (changed)
    {
        int reponse = QMessageBox::warning(this,"Données modifiées","Des données ont été modifiées sans être sauvegardées. Voulez vous les sauvegarder maintenant ?",QMessageBox::Yes | QMessageBox::No);
        if (reponse == QMessageBox::No)
            this->close();
        else
            this->valider();
    }
    else
    {
        this->close();
    }
}

void DialogBien::valider()
{
    // Vérifier les données
    if (!checkData())
    {
        QMessageBox::critical(this,"Données incorrectes","Tous les champs doivent être complétés");
    }
    else
    {   // Si Ok
        m_bien->setDate(ui->dateEdit_DateMiseVente->date());
        m_bien->setPrix(ui->spinBox_prixVente->value());
        m_bien->setSurfHabitable(ui->spinBox_SurfaceHabitable->value());
        m_bien->setSurfJardin(ui->spinBox_SurfaceJardin->value());
        Ville *ville = chercherVille();
        m_bien->setVille(ville);
        // Sauvegarder le bien
        if (m_bien->sauvegarder())
        {
            QMessageBox::information(this,"Données sauvegardées","Bien sauvegardé");
            this->close();
        }
        else
        {
            QMessageBox::critical(this,"Sauvegarde impossible","Le bien n'a pas été sauvegardé. Vérifiez vos données !");
        }
    }
}

bool DialogBien::checkData()
{
    if (ui->dateEdit_DateMiseVente->date().isNull()
        || ui->lineEdit_CodePostal->text().isEmpty()
        )
        return false;
    else return true;
}

Ville* DialogBien::chercherVille()
{
    Ville *ville;
    QString requete = "select * from villes where nom_v='";
    requete += ui->comboBox_Ville->currentText();
    requete += "' and CODE_POSTAL_V='";
    requete += ui->lineEdit_CodePostal->text();
    requete += "'";

    //Debug Infos
    qDebug() << requete;
    //FIN

    m_db = new BDD();
    if (m_db->ouvrir())
    {
        QSqlQuery resultat;
        if (resultat.exec(requete))
        {
            if (resultat.size() < 1)
                QMessageBox::information(this,"Recherche ville", "Aucune ville ne correspond à ce code postal");
            else if (resultat.size() > 1)
                QMessageBox::information(this,"Recherche ville", "Trop de résultats");
            else while (resultat.next())
            {
                //Debug Infos
                qDebug()    << resultat.value(0).toInt()
                            << resultat.value(1).toString()
                            << resultat.value(2).toString()
                            << endl;
                // FIN
                ville = new Ville(resultat.value(0).toInt(), resultat.value(1).toString(), resultat.value(2).toString());
                //Debug Infos
                qDebug()    << ville->getNom()
                            << ville->getNum()
                            << ville->getCodePostal();
                // FIN
            }
        }
    }
    m_db->close();
    return ville;
}
