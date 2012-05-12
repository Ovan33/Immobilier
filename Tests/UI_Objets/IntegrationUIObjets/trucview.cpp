#include "trucview.h"
#include "ui_trucview.h"

TrucView::TrucView(Truc *t, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TrucView)
{
    this->m_truc = t;
    ui->m_label->setText(m_truc->getTextLabel());
    ui->m_pushButton->setText(m_truc->getTextBouton());
    ui->setupUi(this);
}

TrucView::~TrucView()
{
    delete ui;
}

void TrucView::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
