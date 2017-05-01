//
// Created by nakaze on 01/05/17.
//

#include "RotationShape.h"

void RotationShape::apply_itransformation() const {
    glRotatef(-r_angle, r_vector.get_x(), r_vector.get_y(), r_vector.get_z());
    TransformationShape *tmp = dynamic_cast<TransformationShape *>(tr_shape);
    if (tmp) {
        tmp->apply_itransformation();
    }
}

RotationShape::RotationShape(double angle, const Vector vector, Shape *shape)
        : r_angle(angle), r_vector(vector) {
    tr_shape = shape;
}

void RotationShape::apply_transformation() const {
    TransformationShape *tmp = dynamic_cast<TransformationShape *>(tr_shape);
    if (tmp) {
        tmp->apply_transformation();
    }
    glRotatef(r_angle, r_vector.get_x(), r_vector.get_y(), r_vector.get_z());
}

RotationShape::~RotationShape() {
}
