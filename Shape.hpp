#ifndef __SHAPE
#define __SHAPE

#include <g3x.h>
#include <vector>
#include "Point.h"

class Shape {
public:
    Shape() {
    }

    virtual ~Shape() {
    }

    virtual void draw() const = 0;
    virtual bool contains(const Point& p) const = 0;

protected:
    int nbpoints;
    std::vector<Vector*> pts;
    std::vector<Normal*> nor;
};

#endif
