#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QLabel>
#include <QMessageBox>
#include <QDebug>
#include <QSignalMapper>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    monTableauDeWidgets = new QTableWidget(3,1,this);
    setCentralWidget(monTableauDeWidgets);
    for (int i=0; i< 3;i++)
    {
        QString textBouton = "Bouton " +QString::number(i);
        QPushButton *b = new QPushButton(this->monTableauDeWidgets);
        b->setText(textBouton);
        monTableauDeWidgets->setCellWidget(i,0,b);
        QString mess = QString::number(i);

        QSignalMapper *mapper = new QSignalMapper();
        QObject::connect(b,SIGNAL(clicked()),mapper,SLOT(map()));
        mapper->setMapping(b,mess);
        connect(mapper, SIGNAL(mapped(const QString &)), this, SLOT(afficherMessage(const QString &)));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::afficherMessage(QString mess)
{
    QMessageBox::information(this,"Information","Bouton " + mess);
}
