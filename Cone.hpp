#ifndef __CONE
#define __CONE

#include <g3x.h>
#include "CanonicShape.h"
#include "Point.h"

class Cone : public CanonicShape {
public:

    Cone(int n, Vector color); /* Constructeur */
    ~Cone(); /* Destructeur */

	bool contains(const Point& p) const;
};

#endif
