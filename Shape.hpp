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

    virtual bool contains(const Point &p) const = 0;

    std::vector<Vector *> get_points() const {
        return pts;
    }

    void draw() const {
        int i;

        float color[] = {1.0, 0.0, 0.0};
        g3x_Material(color, .25, .25, .25, .25, .25);

        glBegin(GL_POINTS);

        for (i = 0; i < nbpoints; i++) {
            if (pts[i]->is_visible()) {
                glNormal3d(nor[i]->get_x(), nor[i]->get_y(), nor[i]->get_z());
                glVertex3d(pts[i]->get_x(), pts[i]->get_y(), pts[i]->get_z());
            }
        }
        glEnd();
    }

protected:
    int nbpoints;
    std::vector<Vector *> pts;
    std::vector<Normal *> nor;
};

#endif
