#ifndef __CYLINDRE
#define __CYLINDRE

#include <g3x.h>
#include "Shape.hpp"

class Cone : public Shape {
public:

    Cone(int n); /* Constructeur */
    ~Cone(); /* Destructeur */

	bool contains(const Point& p) const;
};

#endif
