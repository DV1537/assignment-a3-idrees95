#ifndef POLYGON_h
#define POLYGON_h

#include "Shape.h"
#include <string>

class Polygon : public Shape
{
private:
    Coords *posOfCoords;
public:
    Polygon(Coords *newPolygon, int numOfCoords);
    ~Polygon();

    double area();
    double circumference();
    double vct(Coords a, Coords b, Coords c);
    bool left(Coords a, Coords b, Coords c);
    double  length(Coords a, Coords b);
    bool isConvex();
    Coords position();
    std::string displayShapeAndCoords() const;
    Polygon &operator =(const Polygon &polygonObject);
    Polygon &operator +(const Coords &otherPolygonObject);
};



#endif