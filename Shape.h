#ifndef SHAPE_H
#define SHAPE_H

#include "Coords.h"

class Shape
{
public:
    std::string shapeType;
    Coords *posOfCoords;
    int numOfCoords;
public:
    std::string getTye() const;
    double distance(Shape *s);

    //-----------pure virtual functions--------//
    virtual double area() = 0;
    virtual double circumference() = 0;
    // Vector product of AB and BC(AB: link vector with point A, point B)
    virtual double vct(Coords a, Coords b, Coords c) = 0;
    // Determine the direction :point c is left with line AB(line with point A, point B) else right
    virtual bool left(Coords a, Coords b, Coords c) = 0;
    // Return length of edge
    virtual double  length(Coords a, Coords b);
    virtual bool isConvex() = 0; 
    virtual Coords position() = 0;
    virtual std::string displayShapeAndCoords() const = 0;
    //virtual Shape &operator =(Shape &s) = 0;

    //--------Definition of Operators-----//
    Shape &operator +(Shape &s);
    friend std::ostream &operator <<(std::ostream &op, const Shape &p);


};

#endif