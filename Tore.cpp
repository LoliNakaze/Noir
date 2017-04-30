//
// Created by nakaze on 30/04/17.
//

#include "Tore.h"

#define RI 0.1

bool Tore::contains(const Point &p) const {
    // TODO
    return false;
}

Tore::~Tore() {
}

Tore::Tore(int n) {
    int i;
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