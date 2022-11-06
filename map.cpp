#include "map.h"
#include "city.h"

Map::Map()
{

}

void Map::addCity(City* city)
{
    citylist.push_back(city);
    qDebug() << "Hier würde der Name der Stadt ausgegeben werden." << city->getName();
}

void Map::draw(QGraphicsScene& scene)
{
    for(auto i= citylist.begin(); i<citylist.end(); ++i)
    {
        (*i)->draw(scene);
    }
    for( auto i= streetlist.begin();i<streetlist.end(); ++i)
    {
        (*i)->draw(scene);
    }
}

bool Map::addStreet(Street* street)
{

    if(this->findCity(street->getstartStadt()->getName())==nullptr or this->findCity(street->getendStadt()->getName())==nullptr)
    {
        qDebug()<<"City does not exist";
        return false;
    }

    streetlist.push_back(street);

    qDebug() << "Hier würde der Name der Straße ausgegeben" << street->getName();
    return true;
}


City *Map::findCity(const QString cityName) const
    {
            for( auto i=citylist.begin(); i!=citylist.end(); ++i)
            {
                if(cityName==(*i)->getName())
                {
                    return *i;
                }

            }
            return nullptr;
}
  City* Map::getOppositeCity(const Street* street, const City* city) const
  {
    if (city == street->getstartStadt())
    {
        return street->getendStadt();
    }

    else if (city == street->getendStadt())
    {
        return street->getstartStadt();
    }

    else
    {
        return nullptr;
    }
}

double Map::getLength(const Street* street) const
{
    double x1 = street->getstartStadt()->getX();
    double x2 = street->getendStadt()->getX();
    double y1 = street->getstartStadt()->getY();
    double y2 = street->getendStadt()->getY();

    double x_laenge = abs(x2 - x1);
    double y_laenge = abs(y2 - y1);

    double length = sqrt(x_laenge*x_laenge + y_laenge*y_laenge);

    return length;
}

QVector<Street*> Map::getStreetList(const City* city) const
{
    QVector<Street*> CityStreetList;
    for(auto i = streetlist.begin(); i != streetlist.end(); i++)
    {
        if(city == (*i)->getstartStadt() || city == (*i)->getendStadt())
        {
            CityStreetList.push_back(*i);
        }
    }

    return CityStreetList;
}

/*QVector<City*> Map::getCityList(const City* city) const
{
    QVector<City*> CityList;
    for(auto i= citylist.begin(); i!= citylist.end(); ++i)
    {
        CityList.push_back(*i);
    }
}*/
