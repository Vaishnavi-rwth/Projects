#ifndef DIALOGADDSTRASSE_H
#define DIALOGADDSTRASSE_H

#include <QDialog>

namespace Ui {
class dialogaddstrasse;
}

class dialogaddstrasse : public QDialog
{
    Q_OBJECT

public:
    explicit dialogaddstrasse(QWidget *parent = nullptr);
    ~dialogaddstrasse();

    QString getstartCity();
    QString getendCity();

private:
    Ui::dialogaddstrasse *ui;
};

#endif // DIALOGADDSTRASSE_H
