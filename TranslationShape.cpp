//
// Created by nakaze on 01/05/17.
//

#include "TranslationShape.h"

void TranslationShape::apply_itransformation(G3Xhmat mat) const {
    double tx = -tr_vector.get_x();
    double ty = -tr_vector.get_y();
    double tz = -tr_vector.get_z();

    G3Xhmat tmp, tmp2;
    g3x_MakeIdentity(tmp);
    g3x_MakeIdentity(tmp2);

    g3x_MakeTranslationXYZ(tmp, tx, ty, tz);

    g3x_ProdHMat(mat, tmp, tmp2);
    G3Xcopymat (mat, tmp2);

    glTranslatef(tx, ty, tz);

    TransformationShape *shape = dynamic_cast<TransformationShape *>(tr_shape);
    if (shape) {
        shape->apply_itransformation(mat);
    }
}

TranslationShape::TranslationShape(const Vector translation, Shape *shape)
        : tr_vector(translation) {
    tr_shape = shape;
}

void TranslationShape::apply_transformation(G3Xhmat mat) const {
    double tx = tr_vector.get_x();
    double ty = tr_vector.get_y();
    double tz = tr_vector.get_z();

    G3Xhmat tmp, tmp2;
    g3x_MakeIdentity(tmp);
    g3x_MakeIdentity(tmp2);
    TransformationShape *shape = dynamic_cast<TransformationShape *>(tr_shape);
    if (shape) {
        shape->apply_transformation(tmp);
    }
    g3x_MakeTranslationXYZ(mat, tx, ty, tz);
    g3x_ProdHMat(tmp, mat, tmp2);
    G3Xcopymat(mat, tmp2);
    glTranslatef(tx, ty, tz);
}

TranslationShape::~TranslationShape() {
}
