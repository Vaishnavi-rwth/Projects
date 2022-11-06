#include "dialog.h"
#include "ui_dialog.h"
#include "city.h"
#include <QMessageBox>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    normal = true;
}

Dialog::~Dialog()
{
    delete ui;
}

bool Dialog::getNormal()
{
    return normal;
}

City* Dialog:: neueStadt()
{
    c = ui->StadtName->text();
       qDebug() << c;
       bool ok;

       char buchstabe[52] = {'A', 'a','B', 'b','C', 'c','D','d','E','F','G','H','I','J','K','L','M','N','O','P','Q',
                             'R','S','T','U','V','W','X','Y','Z','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u',
                             'v','w','x','y','z'};
       normal = true;
       for(int i=0; i<c.size();i++)
       {
           for(int j=0; j<52; j++)
           {

                if(c[i]==buchstabe[j])
                    {
                         //normal = true;
                         break;
                }

               /*else*/ if (j==51)
               {
                   normal= false;
                   break;
               }
               }
           }

       if (normal!=true)
       {
           qDebug() << "City Name enthält ein ungültiges Charakter";
           QMessageBox msg;
           msg.setText("ERROR: \n\nCity name can only contain normal alhpabets");
           msg.exec();
       }

       x_Koordinate = ui->xkoordinate->text().toInt(&ok);

       if (ok == false)
       {
           qDebug() << "please enter a valid integer!";
           normal=false;
       }
       qDebug() << x_Koordinate;

       y_Koordinate = ui->ykoordinate->text().toInt(&ok);
       if (ok == false)
       {
           qDebug() << "please enter a valid integer!";
           normal =false;
       }
       qDebug() << y_Koordinate;

       City* cityy= new City(c, x_Koordinate, y_Koordinate);
       return  cityy;
   }





