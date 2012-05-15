#include "dialogaccueil.h"
#include "ui_dialogaccueil.h"

DialogAccueil::DialogAccueil(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAccueil)
{
    ui->setupUi(this);
    m_menu.setupUi(ui->widget_barreMenu);
    m_menu.label_fenetre->setText("Accueil");
    m_menu.image_fenetre->setPixmap(QPixmap(":/app/accueil"));
    m_menu.pushButton_3->setVisible(false);
    m_menu.pushButton_1->setIcon(QIcon(":/app/rafraichir96"));
    m_menu.pushButton_2->setIcon(QIcon(":/app/quitter96"));

    QObject::connect(m_menu.pushButton_2, SIGNAL(clicked()),this, SLOT(quitter()));
}

DialogAccueil::~DialogAccueil()
{
    delete ui;
}

void DialogAccueil::quitter()
{
    // QApplication::closeAllWindows();
    QApplication::quit();
}
