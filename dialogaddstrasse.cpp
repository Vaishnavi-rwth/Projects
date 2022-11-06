#include "dialogaddstrasse.h"
#include "ui_dialogaddstrasse.h"

dialogaddstrasse::dialogaddstrasse(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialogaddstrasse)
{
    ui->setupUi(this);
}

dialogaddstrasse::~dialogaddstrasse()
{
    delete ui;
}

QString dialogaddstrasse::getstartCity()
{
    return (ui->start_City->text());
}

QString dialogaddstrasse::getendCity()
{
    return (ui->end_City->text());
}
