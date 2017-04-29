#ifndef __SPHERE
#define __SPHERE

#include <g3x.h>
#include "Shape.hpp"
#include "Point.h"

class Sphere : public Shape {
public:
    Sphere(int n); /* Constructeur */
    ~Sphere(); /* Destructeur */
    bool contains(const Point& p) const;
};

#endif
