#ifndef __SPHERE
#define __SPHERE

#include <g3x.h>
#include "CanonicShape.h"
#include "Point.h"

class Sphere : public CanonicShape {
public:
    Sphere(int n); /* Constructeur */
    ~Sphere(); /* Destructeur */
    bool contains(const Point& p) const;
};

#endif
