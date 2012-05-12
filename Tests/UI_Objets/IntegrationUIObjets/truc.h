#ifndef TRUC_H
#define TRUC_H

#include <QObject>

class Truc : public QObject
{
Q_OBJECT
public:
    explicit Truc(QObject *parent = 0);
    QString getTextLabel();
    QString getTextBouton();

private:
    QString m_textLabel;
    QString m_textBouton;

signals:

public slots:

};

#endif // TRUC_H
