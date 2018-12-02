#include "Triangle.h"

Triangle::Triangle(Coords posOfNewTriangle[])
{
    this->shapeType = "Triangle";
    this->numOfCoords = 3;
    int i;
    for(i = 0; i < this->numOfCoords; i++)
    {
        posOfCoords[i] = posOfNewTriangle[i];
    }
}

double Triangle::area()
{
    int i, j, count;
    double area = 0.0;
    j = numOfCoords - 1;
    count = this->numOfCoords;
    if (!(isConvex()))
    {
        return -1;
    }
    else
    {
        for(i = 0; i < count; i++)
        {
            area += (posOfCoords[j].xCoords + posOfCoords[i].xCoords) -
                (posOfCoords[j].yCoords - posOfCoords[i].yCoords);
            j = i;
        }
         area = abs(area / 2.0);
        if (area > 0)
        {
            return area;
        }
    }
    return area;
}

double Triangle::vct(Coords a, Coords b, Coords c)
{
    return ((b.xCoords - a.xCoords) * (c.yCoords - a.yCoords) - (b.yCoords - a.yCoords) * (c.xCoords - a.xCoords));
}

bool Triangle::left(Coords a, Coords b, Coords c)
{   
    bool isLeft = false;
    if (vct(a, b, c) >= 0)
    {
        isLeft = true;
    }
    else
    {
        isLeft = false;
    }
    return isLeft;
}

double Triangle::length(Coords a, Coords b)
{
    double len;
    len = sqrt(pow(a.xCoords - b.xCoords, 2.0) + pow(a.yCoords - b.yCoords, 2.0));
    return len;
}

double Triangle::circumference()
{
    double len = 0.0;
    int count = this->numOfCoords;
    int i;
    for(i = 0; i < count -1; i++)
    {
        len += length(this->posOfCoords[i], this->posOfCoords[i + 1]);
    }
    return len + length(this->posOfCoords[0], this->posOfCoords[count -1]);
}

bool Triangle::isConvex()
{
    bool ws = false;
    int i, j, k;
    bool *b;
    int count;
    count = this->numOfCoords;
    b = new bool[count];
    if (area() > 0)
    {
        ws = true;
    }
    else
    {
        ws = false;
    }
    for(i = 0; i < count; i++)
    {
        j = (i - 1 + count) % count;
        k = (i + 1) % count;
        b[i] = (left(this->posOfCoords[i], this->posOfCoords[j], this->posOfCoords[k]) == ws);
        if (b[i] == 0)
        {
            return true;
        }
    }
    return false;
}

Coords Triangle::position()
{
    Coords centerposition; 
    int i; 
    centerposition.xCoords = 0.0;
    centerposition.yCoords = 0.0;
    for(i = 0; i < this->numOfCoords; i++)
    {
        centerposition.xCoords += centerposition.xCoords;
        centerposition.yCoords += centerposition.yCoords;
    }
    centerposition.xCoords = centerposition.xCoords / this->numOfCoords;
    centerposition.yCoords = centerposition.yCoords / this->numOfCoords;

    return centerposition;
}

std::string Triangle::displayShapeAndCoords() const
{
    std::string totalStr = "";
    int i;
    for (i = 0; i < this->numOfCoords; i++)
    {
        double coordX = std::round(posOfCoords[i].xCoords * 1000) / 1000;
        double coordY = std::round(posOfCoords[i].yCoords * 1000) / 1000;
        totalStr += "X: " + std::to_string(coordX) + ", Y: " + std::to_string(coordY)
        + '\n';
    }
    return totalStr;
}

Triangle &Triangle::operator=(const Triangle &triangleObject)
{
    if(this != &triangleObject)
    {      
        /* if(this->numOfCoords == polygonObject.numOfCoords && posOfCoords)
        { */
            /* int i;
            for(i = 0; i < this->numOfCoords; i++)
            {
                posOfCoords[i] = polygonObject.posOfCoords[i];
            } */
            this->shapeType = triangleObject.shapeType;
            this->numOfCoords = triangleObject.numOfCoords;
            int i;
            for (i = 0; i < this->numOfCoords; i++)
            {
                this->posOfCoords[i] = triangleObject.posOfCoords[i];
            }
       // }         
    }
    return *this;
}
