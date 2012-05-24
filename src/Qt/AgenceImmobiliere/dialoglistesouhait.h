#ifndef DIALOGLISTESOUHAIT_H
#define DIALOGLISTESOUHAIT_H

#include <QDialog>
#include <Client.h>

namespace Ui {
class DialogListeSouhait;
}

class DialogListeSouhait : public QDialog
{
    Q_OBJECT
    
public:
    //explicit DialogListeSouhait(QWidget *parent = 0);
    DialogListeSouhait(Client *client, QWidget *parent = 0);
    ~DialogListeSouhait();
    
private:
    Ui::DialogListeSouhait *ui;
    Client *m_client;
};

#endif // DIALOGLISTESOUHAIT_H
