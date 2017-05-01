#ifndef __OperationShape
#define __OperationShape

#include <g3x.h>
#include "Shape.hpp"

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

private:
    Shape *shape1;
    Shape *shape2;
    OperationType operationType;

    bool contains_aux(G3Xhmat mat, Shape* shape, const Point &p) const;
};

#endif
