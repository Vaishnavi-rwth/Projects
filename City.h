#ifndef CITY_H
#define CITY_H
#include <QString>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QDebug>
#include <QGraphicsView>
#include <QMainWindow>

class City
{
public:
    City(QString name, int x, int y);
    virtual ~City();
    void draw(QGraphicsScene& scene);
    QString getName();
    int getX();
    int getY();

private:
    QString pname;
    int px;
    int py;
};

#endif CITY_H
