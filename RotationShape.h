//
// Created by nakaze on 01/05/17.
//

#ifndef PROJECT_ROTATIONSHAPE_H
#define PROJECT_ROTATIONSHAPE_H

#include <g3x.h>
#include "TransformationShape.h"

class RotationShape : public TransformationShape{
public:
    RotationShape(double angle, const Vector vector, Shape* shape);

    ~RotationShape();

    bool contains(const Point &p) const;

    void apply_itransformation_init(G3Xhmat mat) const;

    void apply_transformation() const;

    void apply_transformation_init() const;

    void apply_itransformation() const;
private:
    double r_angle;
    Vector r_vector;
};


#endif //PROJECT_ROTATIONSHAPE_H
