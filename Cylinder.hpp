#ifndef __CYLINDRE
#define __CYLINDRE

#include <g3x.h>
#include "CanonicShape.h"
#include "Point.h"

class Cylinder : public CanonicShape {
public:
    Cylinder(int n, Vector color); /* Constructeur */
    ~Cylinder(); /* Destructeur */

	bool contains(const Point& p) const;
};

#endif
