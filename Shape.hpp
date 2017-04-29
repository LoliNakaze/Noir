#ifndef __SHAPE
#define __SHAPE

#include <g3x.h>
#include <vector>
#include "Point.h"

class Shape {
public:
    Shape() {
    }

    ~Shape() {
    }

    virtual void draw() = 0;

    virtual bool contains() = 0;

protected:
    int nbpoints;
    std::vector<Vector*> pts;
    std::vector<Normal*> nor;
};

#endif
