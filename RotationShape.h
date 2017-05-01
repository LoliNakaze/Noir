//
// Created by nakaze on 01/05/17.
//

#ifndef PROJECT_ROTATIONSHAPE_H
#define PROJECT_ROTATIONSHAPE_H

#include <g3x.h>
#include "TransformationShape.h"

class RotationShape : public TransformationShape{
public:
    RotationShape(double angle, double x, double y, double z, Shape* shape);

    ~RotationShape();

    void apply_itransformation() const;

    void apply_transformation() const;
private:
    double r_angle;
    double axis_x;
    double axis_y;
    double axis_z;
    Shape* tr_shape;
};


#endif //PROJECT_ROTATIONSHAPE_H
