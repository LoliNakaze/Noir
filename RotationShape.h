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

    void apply_itransformation() const;

    void apply_transformation() const;
private:
    double r_angle;
    Vector r_vector;
};


#endif //PROJECT_ROTATIONSHAPE_H
