#include "dialogaddstreet.h"
#include "ui_dialogaddstreet.h"



DialogAddStreet::DialogAddStreet(QWidget *parent) : QDialog(parent), ui(new Ui::DialogAddStreet)
{
    ui->setupUi(this);
}

DialogAddStreet::~DialogAddStreet()
{
    delete ui;
}

QString DialogAddStreet:: getStartCity()
{
    return (ui->Start_City->text());
}

QString DialogAddStreet:: getEndCity()
{
    return (ui->End_City->text());
}
