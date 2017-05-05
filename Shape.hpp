#ifndef __SHAPE
#define __SHAPE

#include <g3x.h>
#include <vector>
#include "Point.h"

class Shape {
public:
    Shape() {
    }

    virtual ~Shape() {
    }

    virtual bool contains(const Point &p) const = 0;

    void initShape() {
        g3x_MakeIdentity(matrice_transformation);
        g3x_MakeIdentity(matrice_transformation_inverse);
    }

    virtual std::vector<Point *> get_points() const = 0;
    virtual std::vector<Point *> get_canonic_points() const = 0;

    virtual void draw() const = 0;

    G3Xhmat matrice_transformation;
    G3Xhmat matrice_transformation_inverse;
};

#endif
