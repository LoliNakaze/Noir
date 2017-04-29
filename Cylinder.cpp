#include "Cylinder.hpp"

Cylinder::Cylinder(int n)
        : nbpoints(n) {
    int i;

    double a, b;
    pts = std::vector<G3Xpoint>(n);
    nor = std::vector<G3Xvector>(n);

    for (i = 0; i < n / 2; i++) {
        a = g3x_Rand_Delta(PI, PI);
        z = g3x_Rand_Delta(0, 1);

        pts[i][0] = nor[i][0] = cos(a);
        pts[i][1] = nor[i][1] = sin(a);
        pts[i][2] = z;
        nor[i][2] = 0;
    }

    for (; i < n; i++) {
        a = g3x_Rand_Delta(PI, PI);
        z = ((g3x_Rand_Delta(0, 1) > 0) ? 1 : -1);
        r = g3x_Rand_Delta(0.5, 0.5);

        pts[i][0] = r * cos(a);
        pts[i][1] = r * sin(a);
        pts[i][2] = nor[i][2]
        z;
        nor[i][0] = nor[i][1] = 0;
    }
}

void Cylinder::~Cylinder() {
    delete pts;
    delete nor;
}

void Cylinder::draw() {
    int i;

    g3x_Material(G3Xr, .25, .25, .25, .25, .25);

    glBegin(GL_POINTS);

    for (i = 0; i < nbpoints; i++) {
        glNormal3dv(nor[i]);
        glVertex3dv(pts[i]);
    }
    glEnd();
}
