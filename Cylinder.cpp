#include "Cylinder.hpp"

Cylinder::Cylinder(int n){
    int i;
    nbpoints = n;


    double a, z, r;
    pts = std::vector<Vector*>(n);
    nor = std::vector<Normal*>(n);

    for (i = 0; i < (2*n/ 3); i++) {
        a = g3x_Rand_Delta(PI, PI);
        z = g3x_Rand_Delta(0, 1);

        pts[i] = new Vector(cos(a), sin(a) , z );
        nor[i] = new Vector(cos(a), sin(a) , 0 );
        // pts[i][0] = nor[i][0] = cos(a);
        // pts[i][1] = nor[i][1] = sin(a);
        // pts[i][2] = z;



        // nor[i][2] = 0;
    }

    for (; i < n; i++) {
        a = g3x_Rand_Delta(PI, PI);
        z = ((g3x_Rand_Delta(0, 1) > 0) ? 1 : -1);
        r = g3x_Rand_Delta(0.5, 0.5);

        pts[i] = new Vector( r * cos(a), r * sin(a) , z );

        nor[i] = new Vector(0, 0 , z );

        // pts[i][0] = r * cos(a);
        // pts[i][1] = r * sin(a);
        // pts[i][2] = nor[i][2] = z;
        // nor[i][0] = nor[i][1] = 0;
    }
}


void Cylinder::draw() const {
    int i;

    float color[] = {0.0, 1.0, 0.0};
    g3x_Material(color, .25, .25, .25, .25, .25);

    glBegin(GL_POINTS);

    for (i = 0; i < nbpoints; i++) {
        glNormal3d(nor[i]->get_x(), nor[i]->get_y(), nor[i]->get_z());
        glVertex3d(pts[i]->get_x(), pts[i]->get_y(), pts[i]->get_z());
    }
    glEnd();
}


bool Cylinder::contains(const Point &p) const {
    if ( p.get_z() > 1 || p.get_z() < 1  || ( (p.get_x()*p.get_x()) + (p.get_y()*p.get_y()) > 1 ) ){
        return false;
    }
    return true;
}

Cylinder::~Cylinder() {
}
