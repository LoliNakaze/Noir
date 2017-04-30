//
// Created by nakaze on 30/04/17.
//

#ifndef PROJECT_TORE_H
#define PROJECT_TORE_H

#include <g3x.h>
#include "Shape.hpp"
#include <math.h>

class Tore : public Shape {
public:
    Tore(int n); /* Constructeur */
    ~Tore(); /* Destructeur */

    bool contains(const Point &p) const;
};


#endif //PROJECT_TORE_H
