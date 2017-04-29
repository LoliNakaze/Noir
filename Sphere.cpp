#include "Sphere.hpp"

Sphere::Sphere(int n) {
    int i;
    nbpoints = n;

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

void Sphere::draw() const {
    int i;

    float color[] = {1.0, 0.0, 0.0};
    g3x_Material(color, .25, .25, .25, .25, .25);

    glBegin(GL_POINTS);

    for (i = 0; i < nbpoints; i++) {
        glNormal3d(nor[i]->get_x(), nor[i]->get_y(), nor[i]->get_z());
        glVertex3d(pts[i]->get_x(), pts[i]->get_y(), pts[i]->get_z());
    }
    glEnd();
}

bool Sphere::contains(const Point &p) const {
    return p.squared_norm() <= 1.0;
}

Sphere::~Sphere() {
}
