#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "map.h"
#include "mapio.h"
#include "mapionrw.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_teste_was_clicked();


    void on_actionExit_triggered();

    void on_actionClear_Scene_triggered();

    void on_actionAbout_triggered();

    void on_pushButtontest_draw_city_clicked();

    void on_TestDrawMap_clicked();

    void on__test_DrawStreet_clicked();

    void on_pushButton_AbstractMap_clicked();

    void on_checkBox_clicked();

    void on_pushButton_Add_City_clicked();

    void on_pushButton_test_AbstractMap_clicked();

    void on_pushButton_test_Dijkstra_clicked();

    void on_pushButton_AddStreet_clicked();

    void on_pushButton_fillMap_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene scene;
    Map map;
    MapIo* mapio;

};
#endif // MAINWINDOW_H
