#include "OperationShape.hpp"
#include <iostream>
#include <math.h>

OperationShape::OperationShape(Shape *s1, Shape *s2, OperationType ot)
        : shape1(s1), shape2(s2), operationType(ot) {
    std::vector<Point *> s1points = s1->get_points();
    std::vector<Point *> s2points = s2->get_points();
    std::vector<Point *> s1points_canonic = s1->get_canonic_points();
    std::vector<Point *> s2points_canonic = s2->get_canonic_points();

    switch (ot) {
        case INTERSECTION:
            for (int i = 0; i < s2points.size(); i++) {
                s2points_canonic[i]->set_visibility(s2points_canonic[i]->is_visible() &&
                                                    s1->contains(Point(s2points[i]->get_x(), s2points[i]->get_y(),
                                                                       s2points[i]->get_z())));
            }

            for (int i = 0; i < s1points.size(); i++) {
                s1points_canonic[i]->set_visibility(s1points_canonic[i]->is_visible() &&
                                                    s2->contains(
                                                            Point(s1points[i]->get_x(), s1points[i]->get_y(),
                                                                  s1points[i]->get_z())));
            }
            break;
        case UNION:
            for (int i = 0; i < s2points.size(); i++) {
                s2points_canonic[i]->set_visibility(s2points_canonic[i]->is_visible() &&
                                                    !s1->contains(Point(s2points[i]->get_x(), s2points[i]->get_y(),
                                                                        s2points[i]->get_z())));
            }

            for (int i = 0; i < s1points.size(); i++) {
                s1points_canonic[i]->set_visibility(s1points_canonic[i]->is_visible() &&
                                                    !s2->contains(
                                                            Point(s1points[i]->get_x(), s1points[i]->get_y(),
                                                                  s1points[i]->get_z())));
            }
            break;
        case SUBTRACTION:
            for (int i = 0; i < s1points.size(); i++) {
                s1points_canonic[i]->set_visibility(s1points_canonic[i]->is_visible() &&
                                                    !s2->contains(
                                                            Point(s1points[i]->get_x(), s1points[i]->get_y(),
                                                                  s1points[i]->get_z())));
            }

            for (int i = 0; i < s2points.size(); i++) {
                s2points_canonic[i]->set_visibility(false);
            }
            break;
    }
}

OperationShape::~OperationShape() {
}

bool OperationShape::contains_aux(G3Xhmat mat, Shape *shape, const Point &p) const {
    G3Xhmat tmp;
    CanonicShape *cshape;
    TransformationShape *tshape;
    OperationShape *oshape;

    if (cshape = dynamic_cast<CanonicShape *>(shape)) {
        g3x_ProdHMat(mat, cshape->matrice_transformation_inverse, tmp);
        G3Xpoint point = {0, 0, 0};
        G3Xpoint raw = {p.get_x(), p.get_y(), p.get_z()};
        g3x_ProdHMatPoint(tmp, raw, point);
        return cshape->contains(p);
    } else if (tshape = dynamic_cast<TransformationShape *>(shape)) {
        return contains_aux(mat, tshape->origin_shape(), p);
    } else if (oshape = dynamic_cast<OperationShape *>(shape)) { // OperationShape
        g3x_ProdHMat(mat, oshape->matrice_transformation_inverse, tmp);
        switch (operationType) {
            case UNION:
                return contains_aux(tmp, oshape->shape1, p) || contains_aux(tmp, oshape->shape2, p);
            case INTERSECTION:
                return contains_aux(tmp, oshape->shape1, p) && contains_aux(tmp, oshape->shape2, p);
            case SUBTRACTION:
                return contains_aux(tmp, oshape->shape1, p) && !contains_aux(tmp, oshape->shape2, p);
            default:
                std::cerr << "Unknown operation type : " << operationType << std::endl;
                return false;
        }
    } else {
        std::cerr << "Unknown shape type in contains_aux" << std::endl;
        return false;
    }
}

bool OperationShape::contains(const Point &p) const {
//    G3Xhmat mat;
//    g3x_MakeIdentity(mat);
//
//    return contains_aux(mat, (Shape *) this, p);
    switch (operationType) {
        case INTERSECTION:
            return shape1->contains(p) && shape2->contains(p);
        case UNION:
            return shape1->contains(p) || shape2->contains(p);
        case SUBTRACTION:
            return shape1->contains(p) && !shape2->contains(p);
    }
}

void OperationShape::draw() const {
    shape1->draw();
    shape2->draw();
}

static std::vector<Point *> insert(std::vector<Point *> points1, std::vector<Point *> points2) {
    std::vector<Point *> operationPoints;
    int sizePoints1 = points1.size();
    int sizePoints2 = points2.size();

    operationPoints.insert(operationPoints.end(), &points1[0], &points1[sizePoints1]);
    operationPoints.insert(operationPoints.end(), &points2[0], &points2[sizePoints2]);

    return operationPoints;
}

std::vector<Point *> OperationShape::get_points() const {
    return insert(shape1->get_points(), shape2->get_points());
}

std::vector<Point *> OperationShape::get_canonic_points() const {
    return insert(shape1->get_canonic_points(), shape2->get_canonic_points());
}


