#include "Shape.h"

std::string Shape::getTye() const
{
    return this->shapeType;
    /* std::string res;
    switch(this->numOfCoords)
    {
        case 1:
            res = "Point";
            break;
        case 2:
            res = "Line";
            break;
        case 3: 
            res = "Triangle";
            break;
        default:
            res = "Polygon";
            break;
    }
    return res; */
}

double Shape::distance(Shape *s)
{
    double x1CenterPosition = this->position().xCoords;
    double x2CenterPosition = s->position().xCoords;
    double y1CenterPosition = this->position().yCoords;
    double y2CenterPosition = s->position().yCoords;

    double distanceToCenter = 0.0;
    distanceToCenter = sqrt(pow(x1CenterPosition - x2CenterPosition, 2.0) +
               pow(y1CenterPosition - y2CenterPosition, 2.0));
    return distanceToCenter;
}

Shape &Shape::operator+(Shape &s)
{
    if (this == &s)
    {
        return *this;
    }
    int count;
    count = this->numOfCoords + s.numOfCoords;
    int j;
    for(j = this->numOfCoords; j < count; j++)
    {
        this->posOfCoords[j] = s.posOfCoords[j - this->numOfCoords];
    }
    std::string res;
    switch(count)
    {
        case 1:
            res = "Point";
            break;
        case 2:
            res = "Line";
            break;
        case 3: 
            res = "Triangle";
            break;
        default:
            res = "Polygon";
            break;
    }
    this->shapeType = res;
    this->numOfCoords = count;
    return *this;
}

std::ostream &operator <<(std::ostream &op, const Shape &p)
{
    op << p.displayShapeAndCoords() << std::endl;
    return op;
}