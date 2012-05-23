#ifndef WIDGETBIEN_H
#define WIDGETBIEN_H

#include <QWidget>
#include <QPushButton>
#include <QDateEdit>
#include <Ville.h>
#include <QDate>

namespace Ui {
    class WidgetBien;
}

class WidgetBien : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetBien(QWidget *parent = 0);
    ~WidgetBien();

    QPushButton getBoutonDialogBien();
    QPushButton getBoutonSupprimerBien;
    int getPrixVente();
    int getSurfaceHabitable();
    int getSurfaceJardin();
    QDateEdit* getBoutonDate();
    Ville* getVille();

    void setPrixVente(int prix);
    void setSurfaceHabitable(int surf);
    void setSurfaceJardin(int surf);
    void setVille(QString ville);
    void setCodePostal(QString cp);
    void setDateMiseVente(QDate date);

private:
    Ui::WidgetBien *ui;
};

#endif // WIDGETBIEN_H
