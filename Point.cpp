//
// Created by nakaze on 29/04/17.
//

#include "Point.h"

Point::Point(double x, double y, double z)
        : px(x), py(y), pz(z) {
}

Point::~Point() {}

double Point::squared_norm() const {
    return px * px + py * py + pz * pz;
}

double Point::get_x() const {
    return px;
}

double Point::get_y() const {
    return py;
}

double Point::get_z() const {
    return pz;
}