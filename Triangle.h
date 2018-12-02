#ifndef TRAINGLE_H
#define TRAINGLE_H

#include "Shape.h"

class Triangle : public Shape
{
private:
    Coords posOfCoords[3]; // because a triangle has three vertices
public:
    Triangle(Coords posOfNewTriagle[]);

    double area();
    double circumference();
    double vct(Coords a, Coords b, Coords c);
    bool left(Coords a, Coords b, Coords c);
    double  length(Coords a, Coords b);
    bool isConvex();
    Coords position();
    std::string displayShapeAndCoords() const;
    Triangle &operator =(const Triangle &triangleObject);

};
#endif