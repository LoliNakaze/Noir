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
    TransformationShape() {};

    virtual ~TransformationShape() {
    }

    bool contains(const Point &p) const {
        return tr_shape->contains(p);
    };

    Shape *origin_shape() const {
        Shape *res = tr_shape;
        TransformationShape *tmp;
        while ((tmp = dynamic_cast<TransformationShape *>(res)))
            res = tmp->tr_shape;
        return res;
    }

    std::vector<Point *> get_points() const {
        return origin_shape()->get_points();
    }

    void draw() const {
        origin_shape()->draw();
    }

    virtual void apply_itransformation() const = 0;

    virtual void apply_transformation() const = 0;

    virtual void apply_transformation_init() const = 0;

    virtual void apply_itransformation_init(G3Xhmat mat) const = 0;

protected:
    Shape *tr_shape;
};


#endif //PROJECT_TRANSFORMATIONSHAPE_H
