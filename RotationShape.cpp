//
// Created by nakaze on 01/05/17.
//

#include "RotationShape.h"

void RotationShape::apply_itransformation(G3Xhmat mat) const {
    G3Xhmat tmp, tmp2;
    g3x_MakeIdentity(tmp);
    g3x_MakeIdentity(tmp2);

    if (r_vector.get_x()) g3x_MakeRotationX(tmp, -r_angle);
    if (r_vector.get_y()) g3x_MakeRotationY(tmp, -r_angle);
    if (r_vector.get_z()) g3x_MakeRotationZ(tmp, -r_angle);

    g3x_ProdHMat(mat, tmp, tmp2);
    G3Xcopymat (mat, tmp2);

    glRotatef(-r_angle, r_vector.get_x(), r_vector.get_y(), r_vector.get_z());
    TransformationShape *trShape = dynamic_cast<TransformationShape *>(tr_shape);
    if (trShape) {
        trShape->apply_itransformation(mat);
    }
}

RotationShape::RotationShape(double angle, const Vector vector, Shape *shape)
        : r_angle(angle), r_vector(vector) {
    tr_shape = shape;
}

void RotationShape::apply_transformation(G3Xhmat mat) const {
    G3Xhmat tmp, tmp2;
    g3x_MakeIdentity(tmp);
    g3x_MakeIdentity(tmp2);

    if (r_vector.get_x()) g3x_MakeRotationX(mat, r_angle);
    if (r_vector.get_y()) g3x_MakeRotationY(mat, r_angle);
    if (r_vector.get_z()) g3x_MakeRotationZ(mat, r_angle);

    TransformationShape *trShape = dynamic_cast<TransformationShape *>(tr_shape);
    if (trShape) {
        trShape->apply_transformation(mat);
    }
    g3x_ProdHMat(tmp, mat, tmp2);
    G3Xcopymat(mat, tmp2);
    glRotatef(r_angle, r_vector.get_x(), r_vector.get_y(), r_vector.get_z());
}

RotationShape::~RotationShape() {
}
