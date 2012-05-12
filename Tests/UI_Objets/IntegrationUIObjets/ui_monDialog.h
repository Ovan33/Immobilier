/********************************************************************************
** Form generated from reading UI file 'monDialog.ui'
**
** Created: Fri May 11 21:54:38 2012
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MONDIALOG_H
#define UI_MONDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QGridLayout *gridLayout;
    QLabel *m_label;
    QPushButton *m_bouton;
    QTextEdit *m_textEdit;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(260, 300);
        gridLayout = new QGridLayout(Dialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        m_label = new QLabel(Dialog);
        m_label->setObjectName(QString::fromUtf8("m_label"));
        QFont font;
        font.setFamily(QString::fromUtf8("Liberation Sans"));
        font.setPointSize(14);
        m_label->setFont(font);
        m_label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(m_label, 0, 0, 1, 1);

        m_bouton = new QPushButton(Dialog);
        m_bouton->setObjectName(QString::fromUtf8("m_bouton"));

        gridLayout->addWidget(m_bouton, 1, 0, 1, 1);

        m_textEdit = new QTextEdit(Dialog);
        m_textEdit->setObjectName(QString::fromUtf8("m_textEdit"));

        gridLayout->addWidget(m_textEdit, 2, 0, 1, 1);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", 0, QApplication::UnicodeUTF8));
        m_label->setText(QApplication::translate("Dialog", "TextLabel", 0, QApplication::UnicodeUTF8));
        m_bouton->setText(QApplication::translate("Dialog", "PushButton", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MONDIALOG_H
