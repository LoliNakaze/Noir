#ifndef __CUBE
#define __CUBE

#include <g3x.h>
#include "CanonicShape.h"

class Cube : public CanonicShape {
public:
    Cube(int n); /* Constructeur */
    ~Cube(); /* Destructeur */

    bool contains(const Point &p) const;
};

#endif
