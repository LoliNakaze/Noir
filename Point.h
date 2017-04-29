//
// Created by nakaze on 29/04/17.
//

#ifndef PROJECT_POINT_H
#define PROJECT_POINT_H


class Point {
public:
    Point(double x, double y, double z);

    ~Point();

    double squared_norm() const;

    double get_x() const;

    double get_y() const;

    double get_z() const;

private:
    double px;
    double py;
    double pz;
};

typedef Point Vector, Normal;
#endif //PROJECT_POINT_H
