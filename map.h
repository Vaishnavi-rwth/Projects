#ifndef MAP_H
#define MAP_H
#include "City.h"
#include <QVector>
#include <QDebug>
#include "abstractmap.h"


class Map: public AbstractMap
{
public:
    Map();
    void addCity(City*);
    void draw(QGraphicsScene& scene);
    bool addStreet(Street*);
    City* findCity(const QString cityName) const;
    City* getOppositeCity(const Street* street, const City* city) const;
    double getLength(const Street* street) const;
    QVector<Street*> getStreetList(const City* city) const;
    //QVector<City*> getCityList(const City* city) const;


private:
    QVector<City*> citylist;
    QVector<Street*> streetlist;

};


#endif // MAP_H
