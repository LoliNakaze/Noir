//
// Created by nakaze on 01/05/17.
//

#ifndef PROJECT_SCALESHAPE_H
#define PROJECT_SCALESHAPE_H

#include <g3x.h>
#include "TransformationShape.h"

class ScaleShape : public TransformationShape {
public:
    ScaleShape(const Vector scale, Shape *shape);

    ~ScaleShape();

    bool contains(const Point &p) const;

    void apply_itransformation() const;

    void apply_transformation() const;

private:
    const Vector tr_vector;

    void make_matrix(G3Xhmat mat) const;

    void make_inv_matrix(G3Xhmat mat) const;

    void apply_transformation_init() const;

    void apply_itransformation_init(G3Xhmat mat) const;
};

#endif //PROJECT_SCALESHAPE_H
