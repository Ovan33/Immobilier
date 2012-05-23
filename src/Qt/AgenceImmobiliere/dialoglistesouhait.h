#ifndef DIALOGLISTESOUHAIT_H
#define DIALOGLISTESOUHAIT_H

#include <QDialog>

namespace Ui {
class DialogListeSouhait;
}

class DialogListeSouhait : public QDialog
{
    Q_OBJECT
    
public:
    explicit DialogListeSouhait(QWidget *parent = 0);
    ~DialogListeSouhait();
    
private:
    Ui::DialogListeSouhait *ui;
};

#endif // DIALOGLISTESOUHAIT_H
