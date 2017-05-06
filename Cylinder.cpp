#include "Cylinder.hpp"

Cylinder::Cylinder(int n, Vector color) {
    int i;
    nbpoints = n;
    shape_color = color;

    initShape();

    double a, z, r;
    pts = std::vector<Vector *>(n);
    nor = std::vector<Normal *>(n);

    for (i = 0; i < (2 * n / 3); i++) {
        a = g3x_Rand_Delta(PI, PI);
        z = g3x_Rand_Delta(0, 1);

        pts[i] = new Vector(cos(a), sin(a), z);
        nor[i] = new Vector(cos(a), sin(a), 0);
    }

    for (; i < n; i++) {
        a = g3x_Rand_Delta(PI, PI);
        z = ((g3x_Rand_Delta(0, 1) > 0) ? 1 : -1);
        r = g3x_Rand_Delta(0.5, 0.5);

        pts[i] = new Vector(r * cos(a), r * sin(a), z);
        nor[i] = new Vector(0, 0, z);
    }
}



bool Cylinder::contains(const Point &p) const {
    if (p.get_z() > 1 || p.get_z() < -1 || ((p.get_x() * p.get_x()) + (p.get_y() * p.get_y()) > 1)) {
        return false;
    }
    return true;
}

Cylinder::~Cylinder() {
}
