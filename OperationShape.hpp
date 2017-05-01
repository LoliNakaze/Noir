#ifndef __OperationShape
#define __OperationShape

#include <g3x.h>
#include "Shape.hpp"

enum OperationType {UNION, INTERSECTION, SUBTRACTION}

class OperationShape : public Shape {
public:
    OperationShape(Shape* shape1, Shape* shape2, OperationType type); /* Constructeur */
    ~OperationShape(); /* Destructeur */

    bool contains(const Point &p) const;

protected:
	Shape* shape1;    
	Shape* shape2;    
};

#endif
