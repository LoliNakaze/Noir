//
// Created by nakaze on 29/04/17.
//

#include "Point.h"

static Point origin = Point(0, 0, 0);

Point::Point(double x, double y, double z)
        : px(x), py(y), pz(z), visibility(true) {
}

Point::~Point() {}

double Point::squared_norm() const {
    return squared_dist_to(origin);
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

double Point::squared_dist_to(const Point &p) const {
    double x = px - p.get_x();
    double y = py - p.get_y();
    double z = pz - p.get_z();

    return x * x + y * y + z * z;
}

bool Point::is_visible() const {
    return visibility;
}

void Point::set_visibility(bool b) {
    visibility = b;
}
