#include "Cube.hpp"
#include <iostream>
#include <math.h>

Cube::Cube(int n, Vector color) {
    int i;
    nbpoints = n;
    shape_color = color;

    initShape();

    double a, b, c;
    pts = std::vector<Vector *>(n);
    nor = std::vector<Normal *>(n);
   
    
    for (i = 0; i < n; i++) {

        a = g3x_Rand_Delta(3, 3);
        b = g3x_Rand_Delta(0, 1);
        c = g3x_Rand_Delta(0, 1);

        switch (((int) a) + 1) {
            case 1:
                pts[i] = new Vector(1, b, c);
                nor[i] = new Normal(1, 0, 0);
                break;
            case 2:
                pts[i] = new Vector(-1, b, c);
                nor[i] = new Normal(-1, 0, 0);
                break;
            case 3:
                pts[i] = new Vector(b, 1, c);
                nor[i] = new Normal(0, 1, 0);
                break;
            case 4:
                pts[i] = new Vector(b, -1, c);
                nor[i] = new Normal(0, -1, 0);
                break;
            case 5:
                pts[i] = new Vector(b, c, 1);
                nor[i] = new Normal(0, 0, 1);
                break;
            case 6:
                pts[i] = new Vector(b, c, -1);
                nor[i] = new Normal(b, c, -1);
                break;
            default:
//                std::cout << ((int) a) + 1 << std::endl;
                break;
        }
    }
}

Cube::~Cube() {
}

bool Cube::contains(const Point &p) const {
    return fabs(p.get_x()) <= 1.0 && fabs(p.get_y()) <= 1.0 && fabs(p.get_z()) <= 1.0;
}