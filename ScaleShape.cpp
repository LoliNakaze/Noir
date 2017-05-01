//
// Created by nakaze on 01/05/17.
//

#include "ScaleShape.h"

void ScaleShape::apply_itransformation(G3Xhmat mat) const {
    double sx = 1 / tr_vector.get_x();
    double sy = 1 / tr_vector.get_y();
    double sz = 1 / tr_vector.get_z();

    g3x_MakeHomothetieXYZ(mat, sx, sy, sz);
    glScalef(sx, sy, sz);
    TransformationShape *trShape = dynamic_cast<TransformationShape *> (tr_shape);
    if (trShape) {
        trShape->apply_itransformation(mat);
    }
}

ScaleShape::ScaleShape(const Vector scale, Shape *shape)
        : tr_vector(scale) {
    tr_shape = shape;
}

void ScaleShape::apply_transformation(G3Xhmat mat) const {
    double sx = tr_vector.get_x();
    double sy = tr_vector.get_y();
    double sz = tr_vector.get_z();

    TransformationShape *trShape = dynamic_cast<TransformationShape *> (tr_shape);
    if (trShape) {
        trShape->apply_transformation(mat);
    }

    g3x_MakeHomothetieXYZ(mat, sx, sy, sz);
    glScalef(sx, sy, sz);
}

ScaleShape::~ScaleShape() {
}
