//
// Created by nakaze on 01/05/17.
//

#include "ScaleShape.h"

static void init_inversion_matrix(const Vector scale, Shape *shape) {
    G3Xhmat mat;
    g3x_MakeIdentity(mat);
    g3x_MakeHomothetieXYZ(mat, 1 / scale.get_x(), 1 / scale.get_y(), 1 / scale.get_z());

    Shape *origin = shape;
    if (TransformationShape *tmp = dynamic_cast<TransformationShape *>(shape)) {
        tmp->apply_itransformation_init(mat);
        origin = tmp->origin_shape();
    }

    G3Xcopymat(origin->matrice_transformation_inverse, mat);
}

void ScaleShape::apply_itransformation_init(G3Xhmat mat) const {
    double sx = 1 / tr_vector.get_x();
    double sy = 1 / tr_vector.get_y();
    double sz = 1 / tr_vector.get_z();

    G3Xhmat tmp, tmp2;
    g3x_MakeIdentity(tmp);
    g3x_MakeIdentity(tmp2);

    g3x_MakeHomothetieXYZ(tmp, sx, sy, sz);

    g3x_ProdHMat(mat, tmp, tmp2);
    G3Xcopymat(mat, tmp2);


    glScalef(sx, sy, sz);
    TransformationShape *trShape = dynamic_cast<TransformationShape *> (tr_shape);
    if (trShape) {
        trShape->apply_itransformation_init(mat);
    }
}

ScaleShape::ScaleShape(const Vector scale, Shape *shape)
        : tr_vector(scale) {
    tr_shape = shape;

    apply_transformation_init();
    init_inversion_matrix(scale, shape);
}

void ScaleShape::apply_itransformation() const {
    double sx = 1 / tr_vector.get_x();
    double sy = 1 / tr_vector.get_y();
    double sz = 1 / tr_vector.get_z();

    glScalef(sx, sy, sz);

    TransformationShape *trShape = dynamic_cast<TransformationShape *> (tr_shape);
    if (trShape) {
        trShape->apply_itransformation();
    }
}

void ScaleShape::apply_transformation_init() const {
    Shape *shape = origin_shape();

    G3Xhmat mat, tmpmat;
    g3x_MakeIdentity(mat);
    g3x_MakeHomothetieXYZ(mat, tr_vector.get_x(), tr_vector.get_y(), tr_vector.get_z());
    g3x_MakeIdentity(tmpmat);
    g3x_ProdHMat(shape->matrice_transformation, mat, tmpmat);
    G3Xcopymat(shape->matrice_transformation, tmpmat);
}

void ScaleShape::apply_transformation() const {
    double sx = tr_vector.get_x();
    double sy = tr_vector.get_y();
    double sz = tr_vector.get_z();

    TransformationShape *trShape = dynamic_cast<TransformationShape *> (tr_shape);
    if (trShape) {
        trShape->apply_transformation();
    }

    glScalef(sx, sy, sz);
}

ScaleShape::~ScaleShape() {
}

bool ScaleShape::contains(const Point &p) const {
    G3Xhmat mat;
    make_inv_matrix(mat);

    G3Xpoint point = {p.get_x(), p.get_y(), p.get_z()};
    G3Xpoint res = {0,0,0};
    g3x_ProdHMatPoint(mat, point, res);

    return tr_shape->contains(Point(res[0], res[1], res[2]));
}

void ScaleShape::make_matrix(G3Xhmat mat) const {
    g3x_MakeIdentity(mat);
    g3x_MakeHomothetieXYZ(mat, tr_vector.get_x(), tr_vector.get_y(), tr_vector.get_z());
}

void ScaleShape::make_inv_matrix(G3Xhmat mat) const {
    g3x_MakeIdentity(mat);
    g3x_MakeHomothetieXYZ(mat, 1/tr_vector.get_x(), 1/tr_vector.get_y(), 1/tr_vector.get_z());
}
