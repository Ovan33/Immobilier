#ifndef DIALOGBIEN_H
#define DIALOGBIEN_H

#include <QDialog>
#include <ui_barreMenuFiche.h>

namespace Ui {
    class DialogBien;
}

class DialogBien : public QDialog
{
    Q_OBJECT

public:
    explicit DialogBien(QWidget *parent = 0);
    ~DialogBien();


private:
    Ui::DialogBien *ui;
    Ui::barreMenuFiche m_menu;


};

#endif // DIALOGBIEN_H
