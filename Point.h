#ifndef POINT_H
#define POINT_H

#include "Shape.h"
#include <string>

class Point : public Shape
{
private:
    Coords posOfCoord[1];
public:
    Point(Coords newCoords);

    double area() override;
    double circumference() override;
    double vct(Coords a, Coords b, Coords c) override;
    bool left(Coords a, Coords b, Coords c) override;
    double  length(Coords a, Coords b) override;
    bool isConvex() override;
    Coords position() override;
    std::string displayShapeAndCoords() const override;
    Point &operator =(const Point &pointObject);
};

#endif