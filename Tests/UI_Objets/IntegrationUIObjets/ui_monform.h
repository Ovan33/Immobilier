/********************************************************************************
** Form generated from reading UI file 'monform.ui'
**
** Created: Fri May 11 22:17:55 2012
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MONFORM_H
#define UI_MONFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_monForm
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label;
    QPushButton *pushButton;
    QTextEdit *textEdit;

    void setupUi(QWidget *monForm)
    {
        if (monForm->objectName().isEmpty())
            monForm->setObjectName(QString::fromUtf8("monForm"));
        monForm->resize(361, 300);
        verticalLayout = new QVBoxLayout(monForm);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(monForm);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("Liberation Sans"));
        font.setPointSize(14);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        pushButton = new QPushButton(monForm);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 1, 0, 1, 1);

        textEdit = new QTextEdit(monForm);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        gridLayout->addWidget(textEdit, 2, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);


        retranslateUi(monForm);

        QMetaObject::connectSlotsByName(monForm);
    } // setupUi

    void retranslateUi(QWidget *monForm)
    {
        monForm->setWindowTitle(QApplication::translate("monForm", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("monForm", "TextLabel", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("monForm", "PushButton", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class monForm: public Ui_monForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MONFORM_H
