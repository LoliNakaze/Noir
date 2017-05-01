#include "OperationShape.hpp"
#include <iostream>
#include <math.h>

bool OperationShape::test_contains(G3Xhmat inv1, G3Xhmat mat2, std::vector<Point *> points1,
                                   std::vector<Point *> points2, bool b) {
    for (int i = 0; i < points2.size(); i++) {
        G3Xpoint origin = {points2[i]->get_x(), points2[i]->get_y(), points2[i]->get_z()};
        G3Xpoint scaled = {0, 0, 0};
        G3Xpoint res = {0, 0, 0};

        g3x_ProdHMatPoint(mat2, origin, scaled);
        g3x_ProdHMatPoint(inv1, scaled, res);

        points2[i]->set_visibility(b);
    }
}

OperationShape::OperationShape(Shape *s1, Shape *s2, OperationType ot)
        : shape1(s1), shape2(s2), operationType(ot) {

    std::vector<Point *> points1;
    std::vector<Point *> points2;

    switch (ot) {
        case INTERSECTION:
            points2 = s2->get_points();
            for (int i = 0; i < points2.size(); i++) {
                g3x_ProdHMatPoint()

                G3Xpoint tmp = {points2[i]->get_x(), points2[i]->get_y(), points2[i]->get_z()};
                G3Xpoint res = {0, 0, 0};

                g3x_ProdHMatPoint(s1->matrice_transformation_inverse, tmp, res);

                points2[i]->set_visibility(s1->contains(Point(res[0], res[1], res[2])));
            }

            points1 = s1->get_points();
            for (int i = 0; i < points1.size(); i++) {
                G3Xpoint tmp = {points1[i]->get_x(), points1[i]->get_y(), points1[i]->get_z()};
                G3Xpoint res = {0, 0, 0};

                g3x_ProdHMatPoint(s2->matrice_transformation_inverse, tmp, res);

                points1[i]->set_visibility(s2->contains(Point(res[0], res[1], res[2])));
            }
            break;
        case UNION:
            points2 = s2->get_points();
            for (int i = 0; i < points2.size(); i++) {
                G3Xpoint tmp = {points2[i]->get_x(), points2[i]->get_y(), points2[i]->get_z()};
                G3Xpoint res = {0, 0, 0};

                g3x_ProdHMatPoint(s1->matrice_transformation_inverse, tmp, res);

                points2[i]->set_visibility(!s1->contains(Point(res[0], res[1], res[2])));
            }

            points1 = s1->get_points();
            for (int i = 0; i < points1.size(); i++) {
                G3Xpoint tmp = {points1[i]->get_x(), points1[i]->get_y(), points1[i]->get_z()};
                G3Xpoint res = {0, 0, 0};

                g3x_ProdHMatPoint(s2->matrice_transformation_inverse, tmp, res);

                points1[i]->set_visibility(!s2->contains(Point(res[0], res[1], res[2])));
            }
            break;
        case SUBTRACTION:
            points1 = s1->get_points();
            for (int i = 0; i < points1.size(); i++) {
                G3Xpoint tmp = {points1[i]->get_x(), points1[i]->get_y(), points1[i]->get_z()};
                G3Xpoint res = {0, 0, 0};

                g3x_ProdHMatPoint(s2->matrice_transformation_inverse, tmp, res);

                points1[i]->set_visibility(!s2->contains(Point(res[0], res[1], res[2])));
            }

            points2 = s2->get_points();
            for (int i = 0; i < points2.size(); i++) {
                points2[i]->set_visibility(false);
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
        g3x_ProdHMatPoint(tmp, {p.get_x(), p.get_y(), p.get_z()}, point);
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
                cerr << "Unknown operation type : " << operationType << endl;
                return false;
        }
    } else {
        cerr << "Unknown shape type in contains_aux" << endl;
        return false;
    }
}

bool OperationShape::contains(const Point &p) const {
    G3Xhmat mat;
    g3x_MakeIdentity(mat);

    return contains_aux(mat, this, p);
}

void OperationShape::draw() const {
    shape1->draw();
    shape2->draw();
}

std::vector<Point *> OperationShape::get_points() const {
    std::vector<Point *> operationPoints;
    std::vector<Point *> points1 = shape1->get_points();
    int sizePoints1 = points1.size();

    std::vector<Point *> points2 = shape2->get_points();
    int sizePoints2 = points2.size();

    operationPoints.insert(operationPoints.end(), &points1[0], &points1[sizePoints1]);
    operationPoints.insert(operationPoints.end(), &points2[0], &points2[sizePoints2]);

    return operationPoints;
}


