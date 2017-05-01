//
// Created by nakaze on 01/05/17.
//

#include <cstdio>
#include "ScaleShape.h"

void ScaleShape::apply_itransformation() const {
    glScalef(1/tr_vector.get_x(), 1/tr_vector.get_y(), 1/tr_vector.get_z());
    TransformationShape* trShape = dynamic_cast<TransformationShape*> (tr_shape);
    if (trShape) {
        trShape->apply_itransformation();
    }
}

ScaleShape::ScaleShape(const Vector scale, Shape *shape)
        : tr_vector(scale) {
    tr_shape = shape;
}

void ScaleShape::apply_transformation() const {
    TransformationShape* trShape = dynamic_cast<TransformationShape*> (tr_shape);
    if (trShape) {
        trShape->apply_transformation();
    }
    glScalef(tr_vector.get_x(), tr_vector.get_y(), tr_vector.get_z());
}

ScaleShape::~ScaleShape() {
}
