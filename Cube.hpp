#ifndef __CUBE
#define __CUBE

#include <g3x.h>
#include "Shape.hpp"

class Cube : public Shape {
public:
    Cube(int n); /* Constructeur */
    ~Cube(); /* Destructeur */
    bool contains(G3Xpoint p) const;
    void draw() const;
};

#endif
