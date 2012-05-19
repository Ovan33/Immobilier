#include "monwidget.h"
#include "ui_monwidget.h"

MonWidget::MonWidget(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MonWidget)
{
    ui->setupUi(this);
}

MonWidget::~MonWidget()
{
    delete ui;
}

void MonWidget::changeEvent(QEvent *e)
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
