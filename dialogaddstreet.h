#ifndef DIALOGADDSTREET_H
#define DIALOGADDSTREET_H

#include <QDialog>
#include "map.h"


namespace Ui {
class DialogAddStreet;
}

class DialogAddStreet : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAddStreet(QWidget *parent = nullptr);
    ~DialogAddStreet();

    QString getStartCity();
    QString getEndCity();

private:
    Ui::DialogAddStreet *ui;

};

#endif // DIALOGADDSTREET_H
