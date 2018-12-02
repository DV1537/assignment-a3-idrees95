#include "Line.h"
#include <string>

/* void Line::makeCopy(const Coords &copyOtherCoords)
{
    //this->numOfCoords = copyOtherCoords.numOfCoords;
    for (int i = 0; i < this->numOfCoords;i++)
    {
        
    }
} */

Line::Line(Coords newPosOfCoords[])
{
    this->shapeType = "Point";   
    this->numOfCoords = 2;
    for(int i = 0; i < this->numOfCoords; i++)
    {
        this->posOfCoord[i] = newPosOfCoords[i];
    }
}

/* Line::~Line()
{
    delete[] this->posOfCoord;
} */

double Line::area()
{
    return -1;
}

double Line::circumference()
{
    return 0;
}

bool Line::isConvex()
{
    return false;
}

Coords Line::position()
{
    Coords centerPosition;
    int i;
    centerPosition.xCoords = 0.0;
    centerPosition.yCoords = 0.0;

    for(i = 0; i < this->numOfCoords; i++)
    {
        centerPosition.xCoords += centerPosition.xCoords;
        centerPosition.yCoords += centerPosition.yCoords;
    }
    centerPosition.xCoords = centerPosition.xCoords / this->numOfCoords;
    centerPosition.yCoords = centerPosition.yCoords / this->numOfCoords;

    return centerPosition;
}

std::string Line::displayShapeAndCoords() const
{
    std::string totalStr = "";
    int i;
    for(i = 0; i < this->numOfCoords; i++)
    {
        double coordX = std::round(posOfCoord[i].xCoords * 1000) / 1000;
        double coordY = std::round(posOfCoord[i].yCoords * 1000) / 1000;
        totalStr += "X: " + std::to_string(coordX) + ", Y: " + std::to_string(coordY)
        + '\n';
    }
    return totalStr;
}

Line &Line::operator=(const Line &lineObject)
{
    if (this == &lineObject)
    {
        return *this;
    }
    this->shapeType = lineObject.shapeType;
    this->numOfCoords = lineObject.numOfCoords;

    int i;
    for(i = 0; i < this->numOfCoords; i++)
    {
        posOfCoord[i] = lineObject.posOfCoord[i];
    }
    return *this;
}

