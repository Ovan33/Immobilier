#ifndef WIDGETAGENT_H
#define WIDGETAGENT_H

#include <QWidget>

namespace Ui {
class WidgetAgent;
}

class WidgetAgent : public QWidget
{
    Q_OBJECT
    
public:
    explicit WidgetAgent(QWidget *parent = 0);
    ~WidgetAgent();

    void setNom(QString nom);
    
private:
    Ui::WidgetAgent *ui;
};

#endif // WIDGETAGENT_H
