//
// Created by nakaze on 30/04/17.
//

#ifndef PROJECT_TRANSFORMATIONSHAPE_H
#define PROJECT_TRANSFORMATIONSHAPE_H

#include <g3x.h>
#include <iostream>
#include "Point.h"
#include "Shape.hpp"

class TransformationShape : public Shape {
public:
    TransformationShape(){};

    virtual ~TransformationShape() {
    }

    bool contains(const Point &p) const {
        return tr_shape->contains(p);
    };

    void draw() const {
        fprintf(stderr, "Call draw\n");
        std::cout << tr_shape << std::endl;
        TransformationShape* tmp = dynamic_cast<TransformationShape*>(tr_shape);
        if (tmp) {
            tmp->draw();
            fprintf(stderr, "End draw\n");
        } else {
            tr_shape->draw();
        }
    }

    virtual void apply_itransformation() const = 0;

    virtual void apply_transformation() const = 0;

protected:
    Shape* tr_shape;
};


#endif //PROJECT_TRANSFORMATIONSHAPE_H
