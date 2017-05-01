//
// Created by nakaze on 01/05/17.
//

#include "TranslationShape.h"

void TranslationShape::apply_itransformation() const {
    glTranslatef(-tr_vector.get_x(), -tr_vector.get_y(), -tr_vector.get_z());
    TransformationShape* shape = dynamic_cast<TransformationShape*>(tr_shape);
    if (shape) {
        shape->apply_itransformation();
    }
}

TranslationShape::TranslationShape(const Vector translation, Shape *shape)
        : tr_vector(translation), tr_shape(shape) {
}

void TranslationShape::apply_transformation() const {
    TransformationShape* shape = dynamic_cast<TransformationShape*>(tr_shape);
    if (shape) {
        shape->apply_transformation();
    }
    glTranslatef(tr_vector.get_x(), tr_vector.get_y(), tr_vector.get_z());
}
