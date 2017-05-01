//
// Created by nakaze on 01/05/17.
//

#ifndef PROJECT_SCALESHAPE_H
#define PROJECT_SCALESHAPE_H

#include <g3x.h>
#include "TransformationShape.h"

class ScaleShape : public TransformationShape{
public:
    ScaleShape(const Vector scale, Shape* shape);

    ~ScaleShape();

    void apply_itransformation(G3Xhmat mat) const;

    void apply_transformation(G3Xhmat mat) const;

private:
    const Vector tr_vector;
};

#endif //PROJECT_SCALESHAPE_H
