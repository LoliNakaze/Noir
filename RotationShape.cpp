//
// Created by nakaze on 01/05/17.
//

#include "RotationShape.h"

void RotationShape::apply_itransformation(G3Xhmat mat) const {
    if (r_vector.get_x()) g3x_MakeRotationX(mat, -r_angle);
    if (r_vector.get_y()) g3x_MakeRotationY(mat, -r_angle);
    if (r_vector.get_z()) g3x_MakeRotationZ(mat, -r_angle);

    glRotatef(-r_angle, r_vector.get_x(), r_vector.get_y(), r_vector.get_z());
    TransformationShape *tmp = dynamic_cast<TransformationShape *>(tr_shape);
    if (tmp) {
        tmp->apply_itransformation(mat);
    }
}

RotationShape::RotationShape(double angle, const Vector vector, Shape *shape)
        : r_angle(angle), r_vector(vector) {
    tr_shape = shape;
}

void RotationShape::apply_transformation(G3Xhmat mat) const {
    if (r_vector.get_x()) g3x_MakeRotationX(mat, r_angle);
    if (r_vector.get_y()) g3x_MakeRotationY(mat, r_angle);
    if (r_vector.get_z()) g3x_MakeRotationZ(mat, r_angle);

    TransformationShape *tmp = dynamic_cast<TransformationShape *>(tr_shape);
    if (tmp) {
        tmp->apply_transformation(mat);
    }
    glRotatef(r_angle, r_vector.get_x(), r_vector.get_y(), r_vector.get_z());
}

RotationShape::~RotationShape() {
}
