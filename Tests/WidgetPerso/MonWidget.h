#ifndef MONWIDGET_H
#define MONWIDGET_H

#include <QWidget>
#include <QApplication>
#include <QGroupBox>
#include <QPushButton>
#include <QCheckBox>
#include <QLabel>

/*
  Widget personnalisé composé de:
  - une QGroupBox, container pour tous les autres composants
  - un QLabel, réceptacle pour le QString passé en paramètre du constructeur
  - 3 QCheckbox qui s'affichent dans la QGroupBox
  */

class MonWidget : public QWidget
{
private:
    QGroupBox *m_groupBox;
    QLabel *m_nomClient;
    QCheckBox *m_checkRep1;
    QCheckBox *m_checkRep2;
    QCheckBox *m_checkRep3;

public:
    MonWidget(QString nomClient);
    ~MonWidget();
};

#endif // MONWIDGET_H
