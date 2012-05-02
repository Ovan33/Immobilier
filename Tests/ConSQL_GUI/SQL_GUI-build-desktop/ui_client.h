/********************************************************************************
** Form generated from reading UI file 'client.ui'
**
** Created: Fri Apr 13 14:34:46 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENT_H
#define UI_CLIENT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Client
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *SouhaitBouton;
    QPushButton *BienBouton;

    void setupUi(QWidget *Client)
    {
        if (Client->objectName().isEmpty())
            Client->setObjectName(QString::fromUtf8("Client"));
        Client->resize(555, 129);
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Client->sizePolicy().hasHeightForWidth());
        Client->setSizePolicy(sizePolicy);
        Client->setMaximumSize(QSize(555, 129));
        horizontalLayoutWidget = new QWidget(Client);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(259, 9, 291, 91));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        SouhaitBouton = new QPushButton(horizontalLayoutWidget);
        SouhaitBouton->setObjectName(QString::fromUtf8("SouhaitBouton"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(SouhaitBouton->sizePolicy().hasHeightForWidth());
        SouhaitBouton->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(SouhaitBouton);

        BienBouton = new QPushButton(horizontalLayoutWidget);
        BienBouton->setObjectName(QString::fromUtf8("BienBouton"));
        sizePolicy1.setHeightForWidth(BienBouton->sizePolicy().hasHeightForWidth());
        BienBouton->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(BienBouton);


        retranslateUi(Client);

        QMetaObject::connectSlotsByName(Client);
    } // setupUi

    void retranslateUi(QWidget *Client)
    {
        Client->setWindowTitle(QApplication::translate("Client", "Form", 0, QApplication::UnicodeUTF8));
        SouhaitBouton->setText(QApplication::translate("Client", "Souhait", 0, QApplication::UnicodeUTF8));
        BienBouton->setText(QApplication::translate("Client", "Bien", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Client: public Ui_Client {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENT_H
