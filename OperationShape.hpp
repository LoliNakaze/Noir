#ifndef __OperationShape
#define __OperationShape

#include <g3x.h>
#include "Shape.hpp"
#include "CanonicShape.h"
#include "TransformationShape.h"

enum OperationType {
    UNION, INTERSECTION, SUBTRACTION
};

class OperationShape : public Shape {
public:
    OperationShape(Shape *shape1, Shape *shape2, OperationType type); /* Constructeur */
    ~OperationShape(); /* Destructeur */

    bool contains(const Point &p) const;

    void draw() const;

    std::vector<Point *> get_points() const;

    std::vector<Point *> get_canonic_points() const;

private:
    Shape *shape1;
    Shape *shape2;
    OperationType operationType;
};

#endif
