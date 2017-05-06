#include "Sphere.hpp"

Sphere::Sphere(int n, Vector color) {
    int i;
    nbpoints = n;
    shape_color = color;

    initShape();

    double a, b;
    pts = std::vector<Vector*>(n);
    nor = std::vector<Normal*>(n);

    for (i = 0; i < n; i++) {
        a = g3x_Rand_Delta(PI, PI);
        b = g3x_Rand_Delta(PI / 2, PI / 2);

        pts[i] = new Vector(cos(a) * sin(b), sin(a) * sin(b), cos(b));
        nor[i] = new Normal(cos(a) * sin(b), sin(a) * sin(b), cos(b));
    }
}


bool Sphere::contains(const Point &p) const {
    return p.squared_norm() <= 1.0;
}

Sphere::~Sphere() {
}




