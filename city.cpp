#include "City.h"
#include <QString>
#include <QGraphicsTextItem>
#include <QDebug>
#include <QGraphicsView>
#include <QMainWindow>

City::City(QString name, int x, int y): pname(name), px(x), py(y)
{

}

City::~City()
{

}

void City::draw(QGraphicsScene& scene)
{
    scene.addEllipse(px,py,8,8,QPen(Qt::red),QBrush(Qt::red, Qt::SolidPattern));

    QGraphicsTextItem* text = new QGraphicsTextItem;
    text->setPos(px,py);
    text->setPlainText(pname);
    scene.addItem(text);
}

QString City::getName()
{
    return pname;
}

int City::getX()
{
    return px;
}

int City::getY()
{
    return py;
}
