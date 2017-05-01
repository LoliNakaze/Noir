//
// Created by nakaze on 01/05/17.
//

#include "TranslationShape.h"

void TranslationShape::apply_itransformation(G3Xhmat mat) const {
    double tx = -tr_vector.get_x();
    double ty = -tr_vector.get_y();
    double tz = -tr_vector.get_z();

    g3x_MakeTranslationXYZ(mat, tx, ty, tz);
    glTranslatef(tx, ty, tz);
    TransformationShape* shape = dynamic_cast<TransformationShape*>(tr_shape);
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

    TransformationShape* shape = dynamic_cast<TransformationShape*>(tr_shape);
    if (shape) {
        shape->apply_transformation(mat);
    }
    g3x_MakeTranslationXYZ(mat, tx, ty, tz);
    glTranslatef(tx, ty, tz);
}

TranslationShape::~TranslationShape() {
}
