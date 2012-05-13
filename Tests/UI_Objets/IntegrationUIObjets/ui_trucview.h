/********************************************************************************
** Form generated from reading UI file 'trucview.ui'
**
** Created: Fri May 11 23:29:22 2012
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRUCVIEW_H
#define UI_TRUCVIEW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_TrucView
{
public:
    QVBoxLayout *verticalLayout;
    QPushButton *m_pushButton;
    QLabel *m_label;

    void setupUi(QDialog *TrucView)
    {
        if (TrucView->objectName().isEmpty())
            TrucView->setObjectName(QString::fromUtf8("TrucView"));
        TrucView->resize(232, 116);
        verticalLayout = new QVBoxLayout(TrucView);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        m_pushButton = new QPushButton(TrucView);
        m_pushButton->setObjectName(QString::fromUtf8("m_pushButton"));

        verticalLayout->addWidget(m_pushButton);

        m_label = new QLabel(TrucView);
        m_label->setObjectName(QString::fromUtf8("m_label"));
        QFont font;
        font.setFamily(QString::fromUtf8("Liberation Sans"));
        font.setPointSize(14);
        m_label->setFont(font);
        m_label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(m_label);


        retranslateUi(TrucView);

        QMetaObject::connectSlotsByName(TrucView);
    } // setupUi

    void retranslateUi(QDialog *TrucView)
    {
        TrucView->setWindowTitle(QApplication::translate("TrucView", "Dialog", 0, QApplication::UnicodeUTF8));
        m_pushButton->setText(QApplication::translate("TrucView", "PushButton", 0, QApplication::UnicodeUTF8));
        m_label->setText(QApplication::translate("TrucView", "TextLabel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class TrucView: public Ui_TrucView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRUCVIEW_H
