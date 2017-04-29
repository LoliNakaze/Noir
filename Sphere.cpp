#include "Sphere.hpp"

Sphere::Sphere(int n)
        : nbpoints(n) {
    int i;

    double a, b;
    pts = std::vector<G3Xpoint>(n);
    nor = std::vector<G3Xvector>(n);

    for (i = 0; i < n; i++) {
        a = g3x_Rand_Delta(PI, PI);
        b = g3x_Rand_Delta(PI / 2, PI / 2);

        pts[i][0] = cos(a) * sin(b);
        pts[i][1] = sin(a) * sin(b);
        pts[i][2] = cos(b);
    }

    memcpy(nor, pts, NBPOINTS * sizeof(G3Xcoord));
}

void Sphere::draw() {
    int i;

    g3x_Material(G3Xr, .25, .25, .25, .25, .25);

    glBegin(GL_POINTS);

    for (i = 0; i < nbpoints; i++) {
        glNormal3dv(nor[i]);
        glVertex3dv(pts[i]);
    }
    glEnd();
}

void Sphere::~Sphere() {
    delete pts;
    delete nor;
}
