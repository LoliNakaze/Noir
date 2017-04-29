#ifndef __CONE
#define __CONE

#include <g3x.h>
#include "Shape.hpp"

class Cone : public Shape {
public:

    Cone(int n); /* Constructeur */
    ~Cone(); /* Destructeur */

	bool contains(const Point& p) const;
};

#endif
