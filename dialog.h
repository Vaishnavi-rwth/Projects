#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "city.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    City* neueStadt();
    bool getNormal();
private:
    Ui::Dialog *ui;
    QString c;
    int x_Koordinate;
    int y_Koordinate;
    bool normal;

};

#endif // DIALOG_H
