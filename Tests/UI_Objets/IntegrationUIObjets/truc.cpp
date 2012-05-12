#include "truc.h"

Truc::Truc(QObject *parent) :
    QObject(parent)
{
    m_textBouton = "Texte du bouton";
    this->m_textLabel = "Texte du label";
}

QString Truc::getTextBouton()
{
    return this->m_textBouton;
}

QString Truc::getTextLabel()
{
    return this->m_textLabel;
}
