#include "OperationShape.hpp"
#include <iostream>
#include <math.h>

OperationShape::OperationShape(Shape *s1, Shape *s2, OperationType ot)
        : shape1(s1), shape2(s2), operationType(ot) {

    switch (ot) {
        case INTERSECTION:
            std::vector<Point *> points2 = s2->get_points();
            for (int i = 0; i < points2.size(); i++) {
                G3Xpoint tmp = {points2[i]->get_x(), points2[i]->get_y(), points2[i]->get_z()};
                G3Xpoint res = {0, 0, 0};

                g3x_ProdHMatPoint(s1->matrice_transformation_inverse, tmp, res);

                points2[i]->set_visibility(s1->contains(Point(res[0], res[1], res[2])));
            }

            std::vector<Point *> points1 = s1->get_points();
            for (int i = 0; i < points1.size(); i++) {
                G3Xpoint tmp = {points1[i]->get_x(), points1[i]->get_y(), points1[i]->get_z()};
                G3Xpoint res = {0, 0, 0};

                g3x_ProdHMatPoint(s2->matrice_transformation_inverse, tmp, res);

                points1[i]->set_visibility(s2->contains(Point(res[0], res[1], res[2])));
            }
            break;
/*        case UNION:
            break;
        case SUBTRACTION:
            break;*/
    }
}

OperationShape::~OperationShape() {
}

bool OperationShape::contains(const Point &p) const {
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


