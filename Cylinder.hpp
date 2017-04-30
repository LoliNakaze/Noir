#ifndef __CYLINDRE
#define __CYLINDRE

#include <g3x.h>
#include "Shape.hpp"
#include "Point.h"

class Cylinder : public Shape {
public:
    Cylinder(int n); /* Constructeur */
    ~Cylinder(); /* Destructeur */

	bool contains(const Point& p) const;
};

#endif
