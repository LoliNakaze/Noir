//
// Created by nakaze on 30/04/17.
//

#include <iostream>
#include "Tore.h"

#define RI 0.1

bool Tore::contains(const Point &p) const {
    double length = sqrt(p.squared_norm());
    double x = p.get_x();
    double y = p.get_y();
    double z = p.get_z();
    double a = atan2(z, sqrt(x*x + y*y));
    double b = -atan2(x, y);

    std::cout << z << " / " << length << std::endl;
    std::cout << a << " " << b << std::endl;

    double d = p.squared_dist_to(Point(cos(a) * sin(b), sin(a) * sin(b), cos(b)));
    std::cout << d << " <= " << RI * RI << std::endl;
    return d <= RI * RI;
}

Tore::~Tore() {
}

Tore::Tore(int n) {
    int i;
    initShape();
    nbpoints = n;

    double r1, r2;
    pts = std::vector<Vector *>(n);
    nor = std::vector<Normal *>(n);

    for (i = 0; i < n; i++) {
        double a = g3x_Rand_Delta(PI, PI);
        double b = g3x_Rand_Delta(PI, PI);

        double x = (1+RI * cos(a)) * cos (b);
        double y = (1+RI * cos (a)) * sin (b);
        double z = RI * sin (a);

        pts[i] = new Vector(x, y, z);
        nor[i] = new Normal(x - cos(b), y - sin(b), z);
    }
}