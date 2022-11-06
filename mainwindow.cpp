#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QGraphicsView>
#include <QGraphicsScene>
#include "City.h"
#include "dialog.h"
#include "street.h"
#include "map.h"
#include "mapio.h"
#include "dijkstra.h"
#include"dialogaddstrasse.h"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->graphicsView->setScene(&scene);
    mapio = new MapIoNrw;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_teste_was_clicked()
{
    QString str1 = ui->lineEdit_teste_was->text();
        bool ok;
        int a=str1.toInt(&ok);
        QMessageBox msgBox;

        if (!ok)
        {
            QString str2 = QString("Ihr eingegebener Text: %1").arg(str1);
            qDebug() << str2 << a;
        }
        else
           {
               qDebug() << "Ihre um 4 inkreminierte Zahl: " << a + 4;
           }
        msgBox.setText(str1);
        msgBox.exec();

        int x = rand()*450/RAND_MAX;
        int y = rand()*450/RAND_MAX;
        scene.addRect(y,y,x,x,QPen(Qt::blue),QBrush(Qt::blue, Qt::SolidPattern));
}



void MainWindow::on_actionClear_Scene_triggered()
{
    scene.clear();
}

void MainWindow::on_actionExit_triggered()
{
    close();
}


void MainWindow::on_actionAbout_triggered()
{
        QMessageBox msgBox;
        QString str1 = "My StreetPlanner!";
        QString str2 = "This programm is made by Vaishnavi!";

        msgBox.about(this, str1, str2);
}


void MainWindow::on_pushButtontest_draw_city_clicked()
{
    int randStadtX1 = rand()*80/RAND_MAX;
    int randStadtY1 = rand()*80/RAND_MAX;

    City* city1 =  new City("City 1", randStadtX1, randStadtY1);
    city1->draw(scene);

    int randStadtX2 = rand()*80/RAND_MAX;
    int randStadtY2 = rand()*80/RAND_MAX;

    City* city2 = new City("City 2", randStadtX2, randStadtY2);
    city2->draw(scene);

    qDebug()<<"City 1 und City 2 wurden gezeichnet.";
}


void MainWindow::on_TestDrawMap_clicked()
{
        City* c1 = new City("city c1", 20,50);
        City* c2 = new City("city c2", 40,70);
        City* c3 = new City("city c3", 60,90);

        map.addCity(c1);
        map.addCity(c2);
        map.addCity(c3);
        map.draw(scene);
}


void MainWindow::on__test_DrawStreet_clicked()
{
    City* streetCity1 = new City ("streetCity1",20,145);
    City *streetCity2 = new City ("streetCity2",30,100);
    City* streetCity3 = new City("streetCity3",10,20);
    City *streetCity4 = new City("streetCity4",20,70);
    map.addCity(streetCity1);
    map.addCity(streetCity2);
    map.addCity(streetCity3);
    map.addCity(streetCity4);
   // map.addStreet()

    map.draw(scene);

    Street* street1 = new Street(streetCity1,streetCity2);
    Street* street2 = new Street(streetCity3,streetCity4);
    street1->draw(scene);
    street2->draw(scene);

}




void MainWindow::on_pushButton_AbstractMap_clicked()
{

    Map testMap;
    City *a = new City("a", 0, 0);
    City *b = new City("b", 0, 100);
    City *c = new City("c", 100, 300);
    Street *s = new Street(a, b);
    Street *s2 = new Street(b, c);


    qDebug() << "MapTest: Start Test of the Map";
    {
        qDebug() << "MapTest: adding wrong street";
        bool t1 = testMap.addStreet(s);
        if (t1) {
            qDebug() << "-Error: Street should not be added, if cities have not been added.";
        }
    }

    {
        qDebug() << "MapTest: adding correct street";
        testMap.addCity(a);
        testMap.addCity(b);
        bool t1 = testMap.addStreet(s);
        if (!t1) {
            qDebug() << "-Error: It should be possible to add this street.";
        }
    }

    {
        qDebug() << "MapTest: findCity";
        City* city = testMap.findCity("a");
        if (city != a)
            qDebug() << "-Error: City a could not be found.";

        city = testMap.findCity("b");
        if (city != b)
            qDebug() << "-Error: City b could not be found.";

        city = testMap.findCity("c");
        if (city != nullptr)
            qDebug() << "-Error: If city could not be found 0 should be returned.";
    }

    testMap.addCity(c);
    testMap.addStreet(s2);

    {
        qDebug() << "MapTest: getOppositeCity";
        const City *city = testMap.getOppositeCity(s, a);
        if (city != b)
            qDebug() << "-Error: Opposite city should be b.";

        city = map.getOppositeCity(s, c);
        if (city != nullptr)
            qDebug() << "-Error: Opposite city for a city which is not linked by given street should be 0.";
    }

    {
        qDebug() << "MapTest: streetLength";
        double l = testMap.getLength(s2);
        double expectedLength = 223.6;
        // compare doubles with 5% tolerance
        if (l < expectedLength * 0.95 || l > expectedLength *1.05)
            qDebug() << "-Error: Street Length is not equal to the expected.";

    }

    {
        qDebug() << "MapTest: getStreetList";
        QVector<Street*> streetList1 = testMap.getStreetList(a);
        QVector<Street*> streetList2 = testMap.getStreetList(b);
        if (streetList1.size() != 1) {
            qDebug() << "-Error: One street should be found for city a.";
        }
        else if (*streetList1.begin() != s) {
                qDebug() << "-Error: The wrong street has been found for city a.";
        }

        if (streetList2.size() != 2)
            qDebug() << "-Error: Two streets should be found for city b.";
    }

    qDebug() << "MapTest: End Test of the Map.";
}


void MainWindow::on_pushButton_Add_City_clicked()
{
    Dialog dialog;
       int i = dialog.exec();
       City* c = dialog.neueStadt();
       qDebug() << "Der Rückgabewert: " << i;

       if (i == 1 )
       {
           while(dialog.getNormal()!= true && i==1)
           {
           i=dialog.exec();
           }
           if(dialog.getNormal())
           {
                map.addCity(c);
                c->draw(scene);
           }
       }

       else
       {
           qDebug() << "No new city has been added!";
       }
}



void MainWindow::on_pushButton_test_AbstractMap_clicked()
{
    Map testMap;
    City* a = new City("a", 0, 0);
    City* b = new City("b", 0, 100);
    City* c = new City("c", 100, 300);
    Street* s = new Street(a, b);
    Street* s2 = new Street(b, c);


    qDebug() << "MapTest: Start Test of the Map";
    {
        qDebug() << "MapTest: adding wrong street";
        bool t1 = testMap.addStreet(s);
        if (t1) {
            qDebug() << "-Error: Street should not bee added, if cities have not been added.";
        }
    }

    {
        qDebug() << "MapTest: adding correct street";
        testMap.addCity(a);
        testMap.addCity(b);
        bool t1 = testMap.addStreet(s);
        if (!t1) {
            qDebug() << "-Error: It should be possible to add this street.";
        }
    }

    {
        qDebug() << "MapTest: findCity";
        City* city = testMap.findCity("a");
        if (city != a)
            qDebug() << "-Error: City a could not be found.";

        city = testMap.findCity("b");
        if (city != b)
            qDebug() << "-Error: City b could not be found.";

        city = testMap.findCity("c");
        if (city != nullptr)
            qDebug() << "-Error: If city could not be found 0 should be returned.";
    }

    testMap.addCity(c);
    testMap.addStreet(s2);

    {
        qDebug() << "MapTest: getOppositeCity";
        const City *city = testMap.getOppositeCity(s, a);
        if (city != b)
            qDebug() << "-Error: Opposite city should be b.";

        city = map.getOppositeCity(s, c);
        if (city != nullptr)
            qDebug() << "-Error: Opposite city for a city which is not linked by given street should be 0.";
    }

    {
        qDebug() << "MapTest: streetLength";
        double l = testMap.getLength(s2);
        double expectedLength = 223.6;
        // compare doubles with 5% tolerance
        if (l < expectedLength * 0.95 || l > expectedLength *1.05)
            qDebug() << "-Error: Street Length is not equal to the expected.";

    }

    {
        qDebug() << "MapTest: getStreetList";
        QVector<Street*> streetList1 = testMap.getStreetList(a);
        QVector<Street*> streetList2 = testMap.getStreetList(b);
        if (streetList1.size() != 1) {
            qDebug() << "-Error: One street should be found for city a.";
        }
        else if (*streetList1.begin() != s) {
                qDebug() << "-Error: The wrong street has been found for city a.";
        }

        if (streetList2.size() != 2)
            qDebug() << "-Error: Two streets should be found for city b.";
    }

    qDebug() << "MapTest: End Test of the Map.";
}

void MainWindow::on_checkBox_clicked()
{
    if (ui->checkBox->isChecked()==true)
       {
           ui->TestDrawMap->hide();
           ui->_test_DrawStreet->hide();
           ui->pushButtontest_draw_city->hide();
           ui->pushButton_test_Dijkstra->hide();
           ui->pushButton_test_AbstractMap->hide();
           ui->pushButton_teste_was->hide();
       }

       else if(ui->checkBox->isChecked()==false)
       {
        ui->TestDrawMap->show();
        ui->_test_DrawStreet->show();
        ui->pushButtontest_draw_city->show();
        ui->pushButton_test_Dijkstra->show();
        ui->pushButton_test_AbstractMap->show();
        ui->pushButton_teste_was->show();
       }

}


void MainWindow::on_pushButton_test_Dijkstra_clicked()
{
    Map testMap;
    City* c1 = new City("a", 0, 0);
    City* c2 = new City("b", 0, 100);
    City* c3 = new City("c", 100, 300);
    City* c4= new City("d", 70, -200);



    testMap.addCity(c1);
    testMap.addCity(c2);
    testMap.addCity(c3);
    testMap.addCity(c4);

    Street *teststreet1 = new Street(c1, c2);
    Street *teststreet2 = new Street(c2, c3);
    Street *teststreet3 = new Street(c1, c4);
    Street *teststreet4 = new Street(c3, c4);
    testMap.addStreet(teststreet1);
    testMap.addStreet(teststreet2);
    testMap.addStreet(teststreet3);

    testMap.addStreet(teststreet4);


    testMap.draw(scene);

     QVector<Street*> shortest_path = Dijkstra::search(testMap, c1->getName(), c3->getName());


        for(auto it = shortest_path.begin(); it != shortest_path.end(); it++)
            {
                (*it)->drawRed(scene);
            }
    }



void MainWindow::on_pushButton_AddStreet_clicked()
{
    dialogaddstrasse dialog;
    if(dialog.exec())
    {
        QString startName = dialog.getstartCity();
        QString endName = dialog.getendCity();
        if(map.findCity(startName) != nullptr && map.findCity(endName) != nullptr)
        {
            Street street(map.findCity(startName), map.findCity(endName));
            map.addStreet(&street);
            street.draw(scene);
        }
        else
        {
            qDebug() << "Einer der angegebene Städte existieren auf der Karte nicht";
            QMessageBox msg;
            msg.setText("ERROR: Einer der angegebene Städte existieren auf der Karte nicht");
            msg.exec();
        }

    }
}





void MainWindow::on_pushButton_fillMap_clicked()
{
    mapio->fillMap(map);
    map.draw(scene);
}

