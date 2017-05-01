//
// Created by nakaze on 01/05/17.
//

#include "RotationShape.h"

void RotationShape::apply_itransformation() const {
    glRotatef(-r_angle, axis_x, axis_y, axis_z);
    TransformationShape *tmp = dynamic_cast<TransformationShape *>(tr_shape);
    if (tmp) {
        tmp->apply_itransformation();
    }
}

RotationShape::RotationShape(double angle, double x, double y, double z, Shape *shape)
        : r_angle(angle), axis_x(x), axis_y(y), axis_z(z), tr_shape(shape) {
}

void RotationShape::apply_transformation() const {
    TransformationShape *tmp = dynamic_cast<TransformationShape *>(tr_shape);
    if (tmp) {
        tmp->apply_transformation();
    }
    glRotatef(r_angle, axis_x, axis_y, axis_z);
}

RotationShape::~RotationShape() {
}
