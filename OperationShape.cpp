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
                                                    s1->contains(s2points[i]->toPoint()));
            }

            for (int i = 0; i < s1points.size(); i++) {
                s1points_canonic[i]->set_visibility(s1points_canonic[i]->is_visible() &&
                                                    s2->contains(s1points[i]->toPoint()));
            }
            break;
        case UNION:
            for (int i = 0; i < s2points.size(); i++) {
                s2points_canonic[i]->set_visibility(s2points_canonic[i]->is_visible() &&
                                                    !s1->contains(s2points[i]->toPoint()));
            }

            for (int i = 0; i < s1points.size(); i++) {
                s1points_canonic[i]->set_visibility(s1points_canonic[i]->is_visible() &&
                                                    !s2->contains(s1points[i]->toPoint()));
            }
            break;
        case SUBTRACTION:
            for (int i = 0; i < s1points.size(); i++) {
                s1points_canonic[i]->set_visibility(s1points_canonic[i]->is_visible() &&
                                                    !s2->contains(s1points[i]->toPoint()));
            }

            for (int i = 0; i < s2points.size(); i++) {
                s2points_canonic[i]->set_visibility(false);
            }
            break;
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

static std::vector<Point *> insert(std::vector<Point *> points1, std::vector<Point *> points2) {
    int sizePoints1 = points1.size();
    int sizePoints2 = points2.size();
    std::vector<Point *> operationPoints = std::vector<Point *>(sizePoints1 + sizePoints2);

    for (int i = 0; i < sizePoints1; i++) {
        operationPoints[i] = points1[i];
    }

    for (int i = 0; i < sizePoints2; i++) {
        operationPoints[i + sizePoints1] = points2[i];
    }

    return operationPoints;
}

std::vector<Point *> OperationShape::get_points() const {
    return insert(shape1->get_points(), shape2->get_points());
}

std::vector<Point *> OperationShape::get_canonic_points() const {
    return insert(shape1->get_canonic_points(), shape2->get_canonic_points());
}


