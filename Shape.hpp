#ifndef __SHAPE
#define __SHAPE

#include <g3x.h>

class Shape {
    const int nbpoints;
    std::vector <G3Xpoint> pts;
    std::vector <G3Xvector> nor;

public:
    ~Shape() {
        delete pts;
        delete nor;
    }

    virtual void draw() = 0;

    virtual bool contains() = 1;
};

#endif
