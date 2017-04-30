//
// Created by nakaze on 30/04/17.
//

#ifndef PROJECT_TRANSFORMATIONSHAPE_H
#define PROJECT_TRANSFORMATIONSHAPE_H

#include <g3x.h>
#include "Point.h"
#include "Shape.hpp"

#define TR_TRANSLATE 1
#define TR_ROTATE 2
#define TR_SCALE 3

class TransformationShape : public Shape {
public:
    TransformationShape(int type, const Vector vector, const Shape *shape);

    ~TransformationShape();

    bool contains(const Point &p) const;

    std::vector<Vector *> get_points() const;

    void apply_itransformation() const;

private:
    const int tr_type;
    const Vector tr_vector;
    const Shape *tr_shape;

    void apply_transformation() const;
};


#endif //PROJECT_TRANSFORMATIONSHAPE_H
