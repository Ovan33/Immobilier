#include "dialogbien.h"
#include "ui_dialogbien.h"

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
    qDebug() << "surface habitable : " << m_bien->getSurfHabitable();
    qDebug() << "surface jardin : " << m_bien->getSurfJardin();

    ui->dateEdit_DateMiseVente->setDate(m_bien->getDate());
    ui->comboBox_Ville->setCurrentIndex(0);
    // ui->comboBox_Ville->setItemText(m_bien->getVille()->getNom());

    // SIGNAUX et SLOTS
    QObject::connect(m_menu.pushButton_3, SIGNAL(clicked()), qApp, SLOT(quit()));
    QObject::connect(m_menu.pushButton_1,SIGNAL(clicked()),this,SLOT(close()));
}



DialogBien::~DialogBien()
{
    delete ui;
}

