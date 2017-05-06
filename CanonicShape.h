//
// Created by nakaze on 01/05/17.
//

#ifndef PROJECT_CANONICSHAPE_H
#define PROJECT_CANONICSHAPE_H

#include <g3x.h>
#include <vector>
#include <iostream>
#include "Shape.hpp"

class CanonicShape : public Shape {
public:
    CanonicShape() : shape_color(Vector(255, 255, 255)) {};

    virtual ~CanonicShape() {};

    virtual bool contains(const Point &p) const = 0;

    std::vector<Vector *> get_points() const {
        return pts;
    }

    std::vector<Point *> get_canonic_points() const {
        return pts;
    }

    void negative() const {
        for (int i = 0; i < nbpoints; i++) {
            nor[i]->negative();
        }
    }

    void draw() const {
        int i;

        float color[] = {(float) (shape_color.get_x() / 255), (float) (shape_color.get_y() / 255),
                         (float) (shape_color.get_z() / 255)};
        g3x_Material(color, .25, .25, .25, .25, .25);

        glBegin(GL_POINTS);

        for (i = 0; i < nbpoints; i++) {
            if (pts[i]->is_visible()) {
                /*necessité de caster nos données en G3Xvector et G3Xpoint pour pouvoir utiliser glNormal3dv(normal); et glVertex3dv(point); */
                G3Xvector normal = {nor[i]->get_x(), nor[i]->get_y(), nor[i]->get_z()};
                G3Xpoint point = {pts[i]->get_x(), pts[i]->get_y(), pts[i]->get_z()};
                glNormal3dv(normal);
                glVertex3dv(point);
            }
        }
        glEnd();
    }

protected:
    int nbpoints;
    std::vector<Vector *> pts;
    std::vector<Normal *> nor;
    Vector shape_color;
};


#endif //PROJECT_CANONICSHAPE_H
