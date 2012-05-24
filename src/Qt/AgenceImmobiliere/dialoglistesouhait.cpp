#include "dialoglistesouhait.h"
#include "ui_dialoglistesouhait.h"

//DialogListeSouhait::DialogListeSouhait(QWidget *parent) :
//    QDialog(parent),
//    ui(new Ui::DialogListeSouhait)
//{
//    ui->setupUi(this);
//}

DialogListeSouhait::DialogListeSouhait(Client *client, QWidget *parent):
    QDialog(parent),
    ui(new Ui::DialogListeSouhait)
{
    ui->setupUi(this);
    m_client = client;
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("utf8"));
    this->setWindowTitle("Liste des souhaits");
    m_menu.setupUi(ui->widget_barreMenu);
    m_menu.label_fenetre->setText("Souhaits");
    m_menu.image_fenetre->setPixmap(QPixmap(":/app/souhait96"));
    m_menu.pushButton_3->setVisible(false);
    // Bouton de fermeture
    m_menu.pushButton_1->setIcon(QIcon(":/app/back96"));
    m_menu.pushButton_1->setToolTip("Fermer la fenêtre");
    // Bouton Quitter
    m_menu.pushButton_2->setIcon(QIcon(":/app/quitter96"));
    m_menu.pushButton_2->setToolTip("Quitter l'application");
    //Informations client
    ui->label_NomClient->setText(client->getNom());

    ui->tableWidget_listeSouhaits->setColumnCount(1);
    ui->tableWidget_listeSouhaits->verticalHeader()->hide();
    ui->tableWidget_listeSouhaits->horizontalHeader()->hide();

    chercherSouhait();
    // SIGNAUX et SLOTS
    QObject::connect(m_menu.pushButton_1,SIGNAL(clicked()),this,SLOT(close()));
    QObject::connect(m_menu.pushButton_2,SIGNAL(clicked()),qApp,SLOT(quit()));
    //QObject::connect(ui->pushButton_ajouterBien, SIGNAL(clicked()),this,SLOT(nouveauBien()));
}

DialogListeSouhait::~DialogListeSouhait()
{
    delete ui;
}

void DialogListeSouhait::chercherSouhait()
{
    m_db = new BDD();
    if (m_db->ouvrir())
    {
        QSqlQuery requete(m_db->getDb());
        requete.prepare("select * from souhaits where num_c=:numClient");
        requete.bindValue(":numClient", QString::number(m_client->getNum()));
        if (requete.exec())
        {
            if (requete.size() < 1)
                QMessageBox::information(this,"Recherche client", "Aucun souhait trouvé");
            else
            {
                //Initialisations
                ui->tableWidget_listeSouhaits->setRowCount(requete.size());
                int ligne = 0;
                while (requete.next())
                {
                    WidgetSouhait *souhaitUi = new WidgetSouhait();
                    /*
                    // Debug Infos
                    qDebug()    << requete.value(0) << endl
                                << requete.value(1) << endl
                                << requete.value(2) << endl
                                << requete.value(3) << endl
                                << requete.value(4) << endl;
                                //<< requete.value(5) << endl;
                    //Fin*/
                    // num_s, num_c, budget_max_s, surface_hab_min_s, surface_jardin_min_s

                    Ville *ville = new Ville();
                    Souhait *souhait = new Souhait(requete.value(2).toInt(), requete.value(3).toInt(), requete.value(4).toInt(),ville);

                    souhaitUi->setBudgetMax(souhait->getBudget());
                    souhaitUi->setSurfaceHabitableSouhaitee(souhait->getSurfaceHabitable());
                    souhaitUi->setSurfaceJardinSouhaitee(souhait->getSurfaceJardin());


                    ui->tableWidget_listeSouhaits->setColumnWidth(0,ui->tableWidget_listeSouhaits->width());
                    ui->tableWidget_listeSouhaits->setRowHeight(ligne,souhaitUi->height());
                    ui->tableWidget_listeSouhaits->setCellWidget(ligne,0,souhaitUi);
                    ligne++;

                }
            }
        }
        m_db->close();
    }
}
