//
// Created by nakaze on 30/04/17.
//

#include <iostream>
#include "TransformationShape.h"

static int check_transformation_type(int type) {
    switch (type) {
        case TR_SCALE:
        case TR_ROTATE:
        case TR_TRANSLATE:
            return type;
        default:
            std::cerr << "Bad transformation type.\n" << std::endl;
            return -1;
    }
}

TransformationShape::TransformationShape(int type, const Vector vector,
                                         const Shape *shape)
        : tr_type(check_transformation_type(type)), tr_vector(vector), tr_shape(shape) {
}

TransformationShape::~TransformationShape() {
}

bool TransformationShape::contains(const Point &p) const {
    return false;
}

std::vector<Vector *> TransformationShape::get_points() const {
    return tr_shape->get_points();
}

void TransformationShape::apply_transformation() const {
    switch (tr_type) {
        case TR_TRANSLATE:
            glTranslatef(tr_vector.get_x(), tr_vector.get_y(), tr_vector.get_z());
            break;
        case TR_ROTATE:
            break;
        case TR_SCALE:
            glScalef(tr_vector.get_x(), tr_vector.get_y(), tr_vector.get_z());
            break;
        default:
            std::cerr << "Impossible state.\n" << std::endl;
            break;
    }
}

void TransformationShape::apply_itransformation() const {
    switch (tr_type) {
        case TR_TRANSLATE:
            glTranslatef(-tr_vector.get_x(), -tr_vector.get_y(), -tr_vector.get_z());
            break;
        case TR_ROTATE:
            break;
        case TR_SCALE:
            glScalef(1. / tr_vector.get_x(), 1. / tr_vector.get_y(), 1. / tr_vector.get_z());
            break;
        default:
            std::cerr << "Impossible state.\n" << std::endl;
            break;
    }
}