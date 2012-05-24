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
    this->setWindowTitle("Liste des biens");
    m_menu.setupUi(ui->widget_barreMenu);

}

DialogListeSouhait::~DialogListeSouhait()
{
    delete ui;
}
