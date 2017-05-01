//
// Created by nakaze on 01/05/17.
//

#include "TranslationShape.h"

void TranslationShape::apply_itransformation_init(G3Xhmat mat) const {
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
        shape->apply_itransformation_init(mat);
    }
}

static void init_inversion_matrix(const Vector translation, Shape* shape) {
    G3Xhmat mat;
    g3x_MakeIdentity(mat);
    g3x_MakeTranslationXYZ(mat, -translation.get_x(), -translation.get_y(), -translation.get_z());

    Shape* origin = shape;
    if(TransformationShape* tmp = dynamic_cast<TransformationShape*>(shape)) {
        tmp->apply_itransformation_init(mat);
        origin = tmp->origin_shape();
    }

    G3Xcopymat(origin->matrice_transformation_inverse, mat);
}

void TranslationShape::apply_itransformation() const {
    double tx = -tr_vector.get_x();
    double ty = -tr_vector.get_y();
    double tz = -tr_vector.get_z();

    glTranslatef(tx, ty, tz);

    TransformationShape *shape = dynamic_cast<TransformationShape *>(tr_shape);
    if (shape) {
        shape->apply_itransformation();
    }
}

TranslationShape::TranslationShape(const Vector translation, Shape *shape)
        : tr_vector(translation) {
    tr_shape = shape;

    std::cerr << "Regular transformation" << std::endl;
    apply_transformation_init();
    std::cerr << "Inverse transformation" << std::endl;
    init_inversion_matrix(translation, shape);
    std::cerr << "Object created" << std::endl;
}

void TranslationShape::apply_transformation_init() const {
    std::cerr << "Transformation init" << std::endl;

    Shape* shape = origin_shape();

    std::cerr << shape << std::endl;

    G3Xhmat mat, tmpmat;
    g3x_MakeIdentity(mat);
    g3x_MakeTranslationXYZ(mat, tr_vector.get_x(), tr_vector.get_y(), tr_vector.get_z());
    g3x_MakeIdentity(tmpmat);
    g3x_ProdHMat(shape->matrice_transformation, mat, tmpmat);
    G3Xcopymat(shape->matrice_transformation, tmpmat);
}

void TranslationShape::apply_transformation() const {
    double tx = tr_vector.get_x();
    double ty = tr_vector.get_y();
    double tz = tr_vector.get_z();

    TransformationShape *shape = dynamic_cast<TransformationShape *>(tr_shape);
    if (shape) {
        shape->apply_transformation();
    }
    glTranslatef(tx, ty, tz);
}

TranslationShape::~TranslationShape() {
}
