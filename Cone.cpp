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

        r = (-1/2)*z + 1;

        pts[i] = new Vector(r * cos(a), r * sin(a) , z );
        nor[i] = new Vector(cos(a), sin(a) , 0 );
    }

    /*Face INF*/
    for (; i < n; i++) {
        a = g3x_Rand_Delta(PI, PI);
        z = 0
        r = g3x_Rand_Delta(0.5, 0.5);

        pts[i] = new Vector( r * cos(a), r * sin(a) , z );

        nor[i] = new Vector(0, 0 , z );

       
    }
}&




bool Cone::contains(const Point &p) const {
    return false;
}

Cone::~Cone() {
}
