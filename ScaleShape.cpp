//
// Created by nakaze on 01/05/17.
//

#include "ScaleShape.h"

void ScaleShape::apply_itransformation(G3Xhmat mat) const {
    double sx = 1 / tr_vector.get_x();
    double sy = 1 / tr_vector.get_y();
    double sz = 1 / tr_vector.get_z();

    G3Xhmat tmp, tmp2;
    g3x_MakeIdentity(tmp);
    g3x_MakeIdentity(tmp2);

    g3x_MakeHomothetieXYZ(tmp, sx, sy, sz);

    g3x_ProdHMat(mat, tmp, tmp2);
    G3Xcopymat (mat, tmp2);


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

    G3Xhmat tmp, tmp2;
    g3x_MakeIdentity(tmp);
    g3x_MakeIdentity(tmp2);

    TransformationShape *trShape = dynamic_cast<TransformationShape *> (tr_shape);
    if (trShape) {
        trShape->apply_transformation(tmp);
    }

    g3x_MakeHomothetieXYZ(mat, sx, sy, sz);
    g3x_ProdHMat(tmp, mat, tmp2);
    G3Xcopymat(mat, tmp2);
    glScalef(sx, sy, sz);
}

ScaleShape::~ScaleShape() {
}
