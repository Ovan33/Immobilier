#include "MonWidget.h"

MonWidget::MonWidget(QString nomClient)
{
    // Le parent de m_groupBox est this (instance de MonWidget)
    m_groupBox = new QGroupBox(QString::fromUtf8("Mes données clients"), this);
    m_groupBox->setFixedSize(200,120);

    // Le parent de tous les autres attributs est m_groupBox
    // le label et les checkbox sont donc des enfants de m_groupBox
    m_nomClient = new QLabel(nomClient, m_groupBox);
    m_nomClient->move(10,30);
    m_checkRep1 = new QCheckBox(QString::fromUtf8("Réponse 1"), m_groupBox);
    m_checkRep1->move(10,50);
    m_checkRep2 = new QCheckBox(QString::fromUtf8("Réponse 2"), m_groupBox);
    m_checkRep2->move(10,70);
    m_checkRep3 = new QCheckBox(QString::fromUtf8("Réponse 3"), m_groupBox);
    m_checkRep3->move(10,90);
}

MonWidget::~MonWidget()
{
    delete m_groupBox;
    delete m_nomClient;
    delete m_checkRep1;
    delete m_checkRep2;
    delete m_checkRep3;
}
