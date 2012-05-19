/********************************************************************************
** Form generated from reading UI file 'UI_Widget_AccueilResultat.ui'
**
** Created: Sun Apr 8 20:25:55 2012
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UI_WIDGET_ACCUEILRESULTAT_H
#define UI_UI_WIDGET_ACCUEILRESULTAT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QLabel *label_3;
    QLabel *label_2;
    QPushButton *pushButton_Ok;
    QPushButton *pushButton_Erase;
    QPushButton *pushButton_Nouveau;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(635, 91);
        horizontalLayoutWidget = new QWidget(Dialog);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 10, 621, 81));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetNoConstraint);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_4 = new QLabel(horizontalLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_2->addWidget(label_4);

        label_3 = new QLabel(horizontalLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);


        verticalLayout->addLayout(horizontalLayout_2);

        label_2 = new QLabel(horizontalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);


        verticalLayout_2->addLayout(verticalLayout);


        horizontalLayout->addLayout(verticalLayout_2);

        pushButton_Ok = new QPushButton(horizontalLayoutWidget);
        pushButton_Ok->setObjectName(QString::fromUtf8("pushButton_Ok"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_Ok->sizePolicy().hasHeightForWidth());
        pushButton_Ok->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(pushButton_Ok);

        pushButton_Erase = new QPushButton(horizontalLayoutWidget);
        pushButton_Erase->setObjectName(QString::fromUtf8("pushButton_Erase"));
        sizePolicy.setHeightForWidth(pushButton_Erase->sizePolicy().hasHeightForWidth());
        pushButton_Erase->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(pushButton_Erase);

        pushButton_Nouveau = new QPushButton(horizontalLayoutWidget);
        pushButton_Nouveau->setObjectName(QString::fromUtf8("pushButton_Nouveau"));
        sizePolicy.setHeightForWidth(pushButton_Nouveau->sizePolicy().hasHeightForWidth());
        pushButton_Nouveau->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(pushButton_Nouveau);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Dialog", "NomClient", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Dialog", "AdresseClient", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Dialog", "TelephoneClient", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Dialog", "CodePostal Ville", 0, QApplication::UnicodeUTF8));
        pushButton_Ok->setText(QApplication::translate("Dialog", "Ok", 0, QApplication::UnicodeUTF8));
        pushButton_Erase->setText(QApplication::translate("Dialog", "Effacer", 0, QApplication::UnicodeUTF8));
        pushButton_Nouveau->setText(QApplication::translate("Dialog", "Nouveau", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UI_WIDGET_ACCUEILRESULTAT_H
