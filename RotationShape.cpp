//
// Created by nakaze on 01/05/17.
//

#include "RotationShape.h"

void RotationShape::apply_itransformation_init(G3Xhmat mat) const {
    G3Xhmat tmp, tmp2;
    g3x_MakeIdentity(tmp);
    g3x_MakeIdentity(tmp2);

    if (r_vector.get_x()) g3x_MakeRotationX(tmp, -r_angle);
    if (r_vector.get_y()) g3x_MakeRotationY(tmp, -r_angle);
    if (r_vector.get_z()) g3x_MakeRotationZ(tmp, -r_angle);

    g3x_ProdHMat(mat, tmp, tmp2);
    G3Xcopymat(mat, tmp2);

    glRotatef(-r_angle, r_vector.get_x(), r_vector.get_y(), r_vector.get_z());
    TransformationShape *trShape = dynamic_cast<TransformationShape *>(tr_shape);
    if (trShape) {
        trShape->apply_itransformation_init(mat);
    }
}

static void init_inversion_matrix(double angle, const Vector vector, Shape *shape) {
    G3Xhmat mat;
    g3x_MakeIdentity(mat);

    if (vector.get_x()) g3x_MakeRotationX(mat, -angle);
    if (vector.get_y()) g3x_MakeRotationY(mat, -angle);
    if (vector.get_z()) g3x_MakeRotationZ(mat, -angle);

    Shape *origin = shape;
    if (TransformationShape *tmp = dynamic_cast<TransformationShape *>(shape)) {
        tmp->apply_itransformation_init(mat);
        origin = tmp->origin_shape();
    }

    G3Xcopymat(origin->matrice_transformation_inverse, mat);
}

RotationShape::RotationShape(double angle, const Vector vector, Shape *shape)
        : r_angle(angle), r_vector(vector) {
    tr_shape = shape;

    apply_transformation_init();
    init_inversion_matrix(angle, vector, shape);
}

void RotationShape::apply_transformation_init() const {
    Shape *shape = origin_shape();

    G3Xhmat mat, tmpmat;
    g3x_MakeIdentity(mat);

    if (r_vector.get_x()) g3x_MakeRotationX(mat, r_angle);
    if (r_vector.get_y()) g3x_MakeRotationY(mat, r_angle);
    if (r_vector.get_z()) g3x_MakeRotationZ(mat, r_angle);

    g3x_MakeIdentity(tmpmat);
    g3x_ProdHMat(shape->matrice_transformation, mat, tmpmat);
    G3Xcopymat(shape->matrice_transformation, tmpmat);
}

void RotationShape::apply_transformation() const {
    TransformationShape *trShape = dynamic_cast<TransformationShape *>(tr_shape);
    if (trShape) {
        trShape->apply_transformation();
    }

    glRotatef(r_angle, r_vector.get_x(), r_vector.get_y(), r_vector.get_z());
}

RotationShape::~RotationShape() {
}

void RotationShape::apply_itransformation() const {
    glRotatef(-r_angle, r_vector.get_x(), r_vector.get_y(), r_vector.get_z());
    TransformationShape *trShape = dynamic_cast<TransformationShape *>(tr_shape);
    if (trShape) {
        trShape->apply_itransformation();
    }
}

void RotationShape::make_matrix(G3Xhmat mat) const {
    g3x_MakeIdentity(mat);

    if (r_vector.get_x()) g3x_MakeRotationX(mat, r_angle);
    if (r_vector.get_y()) g3x_MakeRotationY(mat, r_angle);
    if (r_vector.get_z()) g3x_MakeRotationZ(mat, r_angle);
}

void RotationShape::make_inv_matrix(G3Xhmat mat) const {
    g3x_MakeIdentity(mat);
    if (r_vector.get_x()) g3x_MakeRotationX(mat, -r_angle);
    if (r_vector.get_y()) g3x_MakeRotationY(mat, -r_angle);
    if (r_vector.get_z()) g3x_MakeRotationZ(mat, -r_angle);
}
