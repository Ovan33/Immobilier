#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_accueil = new (DialogAccueil);
    m_accueil->exec();
}

MainWindow::~MainWindow()
{
    delete m_accueil;
    delete ui;
}
