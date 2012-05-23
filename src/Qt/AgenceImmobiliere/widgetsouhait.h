#ifndef WIDGETSOUHAIT_H
#define WIDGETSOUHAIT_H

#include <QWidget>

namespace Ui {
class widgetSouhait;
}

class widgetSouhait : public QWidget
{
    Q_OBJECT
    
public:
    explicit widgetSouhait(QWidget *parent = 0);
    ~widgetSouhait();
    
private:
    Ui::widgetSouhait *ui;
};

#endif // WIDGETSOUHAIT_H
