#include "OperationShape.hpp"
#include <iostream>
#include <math.h>

void OperationShape::test_contains(Shape *s1, Shape *s2, G3Xhmat mat2, bool b) {
    G3Xhmat tmp;
    CanonicShape *cshape;
    TransformationShape *tshape;
    OperationShape *oshape;

    if (cshape = dynamic_cast<CanonicShape *>(s2)) {
        std::vector<Point *> points = cshape->get_points();
        g3x_ProdHMat(mat2, cshape->matrice_transformation, tmp);
        for (int i = 0; i < points.size(); i++) {
            G3Xpoint origin = {points[i]->get_x(), points[i]->get_y(), points[i]->get_z()};
            G3Xpoint scaled = {0, 0, 0};

            g3x_ProdHMatPoint(tmp, origin, scaled);

            points[i]->set_visibility(b && s1->contains(Point(scaled[0], scaled[1], scaled[2])));
        }
    } else if (tshape = dynamic_cast<TransformationShape *>(s2)) {
        test_contains(s1, tshape->origin_shape(), mat2, b);
    } else if (oshape = dynamic_cast<OperationShape *>(s2)) {
        g3x_ProdHMat(mat2, oshape->matrice_transformation, tmp);
        test_contains(s1, oshape->shape1, tmp, b);
        test_contains(s1, oshape->shape2, tmp, b);
    }
}

OperationShape::OperationShape(Shape *s1, Shape *s2, OperationType ot)
        : shape1(s1), shape2(s2), operationType(ot) {
    G3Xhmat mat;

    switch (ot) {
        case INTERSECTION:
            g3x_MakeIdentity(mat);
            test_contains(s1, s2, mat, true);

            g3x_MakeIdentity(mat);
            test_contains(s2, s1, mat, true);
            break;
        case UNION:
            g3x_MakeIdentity(mat);
            test_contains(s1, s2, mat, false);

            g3x_MakeIdentity(mat);
            test_contains(s2, s1, mat, false);
            break;
        case SUBTRACTION:
            g3x_MakeIdentity(mat);
            test_contains(s2, s1, mat, false);

            std::vector<Point *> points2 = s2->get_points();
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
    G3Xhmat mat;
    g3x_MakeIdentity(mat);

    return contains_aux(mat, (Shape *) this, p);
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


