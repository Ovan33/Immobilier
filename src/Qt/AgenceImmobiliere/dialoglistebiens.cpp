#include "dialoglistebiens.h"
#include "ui_dialoglistebiens.h"
#include <Bien.h>
#include <widgetbien.h>
#include <QMessageBox>

DialogListeBiens::DialogListeBiens(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogListeBiens)
{
    ui->setupUi(this);
}

DialogListeBiens::DialogListeBiens(Client *client, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogListeBiens)
{
    ui->setupUi(this);
    m_client = client;
    qDebug() << m_client->getNum();
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("utf8"));
    this->setWindowTitle("Liste des biens");
    m_menu.setupUi(ui->widget_barreMenu);
    m_menu.label_fenetre->setText("Biens");
    m_menu.image_fenetre->setPixmap(QPixmap(":/app/bien96"));
    m_menu.pushButton_3->setVisible(false);
    // Bouton de fermeture
    m_menu.pushButton_1->setIcon(QIcon(":/app/annuler96"));
    m_menu.pushButton_1->setToolTip("Fermer la fenêtre");
    // Bouton Quitter
    m_menu.pushButton_2->setIcon(QIcon(":/app/quitter96"));
    m_menu.pushButton_2->setToolTip("Quitter l'application");
    ui->pushButton_ajouterBien->setToolTip("Créer un nouveau bien");
    ui->tableWidget_listeBiens->setColumnCount(1);
    ui->tableWidget_listeBiens->verticalHeader()->hide();
    ui->tableWidget_listeBiens->horizontalHeader()->hide();
    //Informations client
    ui->label_NomClient->setText(client->getNom());
    // Chercher et afficher les biens
    chercherBiens();
    // SIGNAUX et SLOTS
    // QObject::connect(ui->pushButton_ajouterBien,SIGNAL(clicked()),m_dialogBien,SLOT(exec()));
}

DialogListeBiens::~DialogListeBiens()
{
    delete ui;
}

void DialogListeBiens::chercherBiens()
{
    QString requete = "select * from biens where num_c=" + QString::number(m_client->getNum());
    // requete += m_client->getNum();
    // requete +=
    qDebug() << m_client->getNum();
    qDebug() << requete;
    // Exécution de la requête //

    m_db = new BDD();
    if (m_db->ouvrir())
    {
        QSqlQuery resultat;
        if (resultat.exec(requete))
        {
            if (resultat.size() < 1)
                QMessageBox::information(this,"Recherche client", "Aucun bien trouvé");
            else
            {
                // Initialisations
                ui->tableWidget_listeBiens->setRowCount(resultat.size());
                int ligne = 0;
                while (resultat.next())
                {
                    WidgetBien *bienUi = new WidgetBien();
                    Ville *ville = new Ville();
                    QDate date(resultat.value(4).toString().left(4).toInt(),resultat.value(4).toString().mid(5,2).toInt(),resultat.value(4).toString().right(2).toInt());
                    Bien *bien = new Bien(resultat.value(3).toUInt(),date,resultat.value(5).toUInt(),resultat.value(6).toUInt(),ville,m_client);
                    this->m_listeBiens.append(bien);
                    ui->label_NomClient->setText(bien->getClient()->getNom());
                    bienUi->setPrixVente(bien->getPrix());
                    bienUi->setSurfaceHabitable(bien->getSurf(Bien::habitation));
                    bienUi->setSurfaceJardin(bien->getSurf(Bien::jardin));
                    // Manque la date
                    ui->tableWidget_listeBiens->setColumnWidth(0,ui->tableWidget_listeBiens->width());
                    ui->tableWidget_listeBiens->setRowHeight(ligne,bienUi->height());
                    ui->tableWidget_listeBiens->setCellWidget(ligne,0,bienUi);
                    ligne++;
                }
            }
        }
    }
    m_db->close();
}
