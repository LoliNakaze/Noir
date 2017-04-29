#ifndef __SPHERE
#define __SPHERE

#include <g3x.h>
#include "Shape.h"

class Sphere : public Shape {
public:

    Sphere(int n); /* Constructeur */
    ~Sphere(); /* Destructeur */
/*	const bool contains(G3Xpoint p); */
};

#endif
