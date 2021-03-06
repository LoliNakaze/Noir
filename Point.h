//
// Created by nakaze on 29/04/17.
//

#ifndef PROJECT_POINT_H
#define PROJECT_POINT_H


class Point {
public:
    Point(double x, double y, double z);

    ~Point();

    bool is_visible() const;

    void set_visibility(bool b);

    double squared_norm() const;

    double squared_dist_to(const Point &p) const;

    double get_x() const;

    double get_y() const;

    double get_z() const;

    Point toPoint() const;

    void negative();

private:
    double px;
    double py;
    double pz;
    bool visibility;
};

typedef Point Vector, Normal;
#endif //PROJECT_POINT_H
