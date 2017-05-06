//
// Created by nakaze on 30/04/17.
//

#ifndef PROJECT_TRANSFORMATIONSHAPE_H
#define PROJECT_TRANSFORMATIONSHAPE_H

#include <g3x.h>
#include <iostream>
#include "Point.h"
#include "Shape.hpp"

class TransformationShape : public Shape {
public:
    TransformationShape() {};

    virtual ~TransformationShape() {
    }

    bool contains(const Point &p) const {
        G3Xhmat mat;
        make_inv_matrix(mat);

        G3Xpoint point = {p.get_x(), p.get_y(), p.get_z()};
        G3Xpoint res = {0, 0, 0};
        g3x_ProdHMatPoint(mat, point, res);

        return tr_shape->contains(Point(res[0], res[1], res[2]));
    };

    Shape *origin_shape() const {
        Shape *res = tr_shape;
        TransformationShape *tmp;
        while ((tmp = dynamic_cast<TransformationShape *>(res)))
            res = tmp->tr_shape;
        return res;
    }

    std::vector<Point *> get_points() const {
        std::vector<Point *> points = tr_shape->get_points();
        std::vector<Point *> res = std::vector<Point *>(points.size());
        G3Xhmat mat;
        make_matrix(mat);

        for (int i = 0; i < points.size(); i++) {
            G3Xpoint tmp = {points[i]->get_x(), points[i]->get_y(), points[i]->get_z()};
            G3Xpoint scaled = {0, 0, 0};
            g3x_ProdHMatPoint(mat, tmp, scaled);

            res[i] = new Point(scaled[0], scaled[1], scaled[2]);
        }

        return res;
    }

    std::vector<Point *> get_canonic_points() const {
        return origin_shape()->get_canonic_points();
    }

    void draw() const {
        glPushMatrix();
        apply_transformation();
        origin_shape()->draw();
        glPopMatrix();
    }

    virtual void apply_itransformation() const = 0;

    virtual void apply_transformation() const = 0;

    virtual void apply_transformation_init() const = 0;

    virtual void apply_itransformation_init(G3Xhmat mat) const = 0;

protected:
    Shape *tr_shape;

    virtual void make_matrix(G3Xhmat mat) const = 0;

    virtual void make_inv_matrix(G3Xhmat mat) const = 0;
};


#endif //PROJECT_TRANSFORMATIONSHAPE_H
