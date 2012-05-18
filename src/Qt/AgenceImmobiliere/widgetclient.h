#ifndef WIDGETCLIENT_H
#define WIDGETCLIENT_H

#include <QWidget>

namespace Ui {
    class WidgetClient;
}

class WidgetClient : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetClient(QWidget *parent = 0);
    ~WidgetClient();
    void setNom(QString nom);
    void setAdresse(QString adresse);
    void setTelephone(QString tel);
    void setVille(QString ville);
    void setCodePostal(QString cp);
    void setImageBien(QPixmap image);
    void setImageSouhait(QPixmap image);

private:
    Ui::WidgetClient *ui;

};

#endif // WIDGETCLIENT_H
