#ifndef DIALOGCLIENT_H
#define DIALOGCLIENT_H

#include <QDialog>
#include "Client.h"

namespace Ui {
    class DialogClient;
}

class DialogClient : public QDialog
{
    Q_OBJECT

public:
    // explicit DialogClient(Client *client, QWidget *parent = 0);
    explicit DialogClient(Client *client);
    explicit DialogClient();
    ~DialogClient();
    void setClient(Client *client);

private:
    Ui::DialogClient *ui;
    Client *m_client;
};

#endif // DIALOGCLIENT_H
