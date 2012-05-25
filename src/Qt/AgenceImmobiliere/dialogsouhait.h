#ifndef DIALOGSOUHAIT_H
#define DIALOGSOUHAIT_H

#include <QDialog>
#include <Souhait.h>
#include <Ville.h>

namespace Ui {
    class DialogSouhait;
}

class DialogSouhait : public QDialog
{
    Q_OBJECT

public:
    explicit DialogSouhait(QWidget *parent = 0);
    DialogSouhait(Souhait *souhait, QWidget *parent = 0);
    ~DialogSouhait();

private:
    Ui::DialogSouhait *ui;
    Souhait *m_souhait;
    QList<Ville *> m_listeVilles;

};

#endif // DIALOGSOUHAIT_H
