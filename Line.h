#ifndef LINE_H
#define LINE_H

#include "Shape.h"

class Line : public Shape
{
private:
    Coords posOfCoord[2];
    //int numOfCoords;
    // helpful function
    //void makeCopy(const Coords &copyOtherCoords);
public:
    Line(Coords newPosOfCoords[]);

    double area() override;
    double circumference() override;
    double vct(Coords a, Coords b, Coords c) override;
    bool left(Coords a, Coords b, Coords c) override;
    double  length(Coords a, Coords b) override;
    bool isConvex() override;
    Coords position() override;
    std::string displayShapeAndCoords() const override;
    Line &operator =(const Line &lineObject);
};

#endif