#include "Point.h"

Point::Point(Coords newCoords)
{
    this->shapeType = "Point";
    this->numOfCoords = 1;
    this->posOfCoord[0] = newCoords;
}

double Point::area()
{
    return -1;
}

double Point::circumference()
{
    return 0;
}

bool Point::isConvex()
{
    return false;
}

Coords Point::position()
{
    return posOfCoord[0];
}

std::string Point::displayShapeAndCoords() const
{
    std::string totalStr = "";

    double coordX = std::round(posOfCoord[0].xCoords * 1000) / 1000;
    
    double coordY = std::round(posOfCoord[0].yCoords * 1000) / 1000;
    totalStr += "X: " + std::to_string(coordX) + ", Y: " + std::to_string(coordY)
        + '\n';

    return totalStr;
}

Point &Point::operator=(const Point &pointObject)
{
    if (this == &pointObject)
    {
        return *this;
    }
    this->shapeType = pointObject.shapeType;
    this->numOfCoords = pointObject.numOfCoords;

    posOfCoord[0] = pointObject.posOfCoord[0];
    
    return *this;
}
