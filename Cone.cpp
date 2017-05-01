#include "Cone.hpp"

Cone::Cone(int n){
    int i;
    nbpoints = n;

    double a, z, r;
    pts = std::vector<Vector*>(n);
    nor = std::vector<Normal*>(n);

    /*Contour*/
    for (i = 0; i < (2*n/ 3); i++) {
        a = g3x_Rand_Delta(PI, PI);
        z = g3x_Rand_Delta(1, 1);

        r = ((-1.0/2.0)*z) + 1;

        pts[i] = new Vector(r * cos(a), r * sin(a) , z );
        nor[i] = new Vector(cos(a), sin(a) , (sqrt(2))/2);
    }

    /*Face INF*/
    for (; i < n; i++) {
        a = g3x_Rand_Delta(PI, PI);
        z = 0;
        r = g3x_Rand_Delta(0.5, 0.5);

        pts[i] = new Vector( r * cos(a), r * sin(a) , z );

        nor[i] = new Vector(0, 0 , -1 );       
    }
}

bool Cone::contains(const Point &p) const {
    long ray = ((-1.0/2.0) * p.get_z()) + 1;
    if (p.get_z() > 2 || p.get_z() < 0 || 
        ((p.get_x() * p.get_x()) + (p.get_y() * p.get_y()) > ray)) {
        return false;
    }
    return true;
}

Cone::~Cone() {
}
