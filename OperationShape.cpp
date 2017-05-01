#include "OperationShape.hpp"
#include <iostream>
#include <math.h>

OperationShape::OperationShape(Shape* s1, Shape* s2, OperationType ot ) {

    shape1 = s1;
    shape2 = s2;
    operationType = ot;

    switch(ot){
        case INTERSECTION:
            std::vector<Point*> points2 = s2->get_points();
            int sizePoints2 = points2.size();
            for(int i = 0 ; i < sizePoints2 ; i++){
                G3Xpoint tmp = {points2[i]->get_x(),points2[i]->get_y(),points2[i]->get_z()};
                G3Xpoint res = {0,0,0};

                g3x_ProdHMatPoint(s1.matrice_transformation_inverse , tmp, res);

                if( s1->contains(Point(res[0], res[1], res[2])){
                    points2[i]->visibility = true;
                }
                else{
                    points2[i]->visibility = false;
                }    

            }



            std::vector<Point*> points1 = s1->get_points();

            int sizePoints1 = points1.size();
            for(int i = 0 ; i < sizePoints1 ; i++){
                G3Xpoint tmp = {points1[i]->get_x(),points1[i]->get_y(),points1[i]->get_z()};
                G3Xpoint res = {0,0,0};

                g3x_ProdHMatPoint(s2->matrice_transformation_inverse , tmp, res);

                if( s2->contains(Point(res[0], res[1], res[2])){
                    points1[i]->visibility = true;
                }
                else{
                    points1[i]->visibility = false;
                }    

            }

            // std::vector<Point> points1 = s2->get_points();

            // for(int i = 0 ; i < s1->nbpoints ; i++){

            //     if( s2.contains(     points1[i] * s2.matrice_transformation_inverse  ){
            //         points1[i].visibility = true;
            //     }
            //     else{
            //         points1[i].visibility = false;
            //     }    

            // }



        break;
        // case UNION:
        //    std::vector<Point> points2 = s2->get_points();

        //     for(int i = 0 ; i < s2->nbpoints ; i++){

        //         if( s1.contains(     points2[i] * s1.matrice_transformation_inverse  ){
        //             points2[i].visibility = false;
        //         }
        //         else{
        //             points2[i].visibility = true;
        //         }    

        //     }

        //     std::vector<Point> points1 = s2->get_points();

        //     for(int i = 0 ; i < s1->nbpoints ; i++){

        //         if( s2.contains(     points1[i] * s2.matrice_transformation_inverse  ){
        //             points1[i].visibility = false;
        //         }
        //         else{
        //             points1[i].visibility = true;
        //         }    

        //     }

        // break;

        // case SUBTRACTION:
        //    std::vector<Point> points2 = s2->get_points();
        //     for(int i = 0 ; i < s2->nbpoints ; i++){
        //         points2[i].visibility = false;   
        //     }

        //     std::vector<Point> points1 = s2->get_points();

        //     for(int i = 0 ; i < s1->nbpoints ; i++){
        //         if( s2.contains(     points1[i] * s2.matrice_transformation_inverse  ){
        //             points1[i].visibility = false;
        //         }
        //         else{
        //             points1[i].visibility = true;
        //         }    
        //     }

        // break;

    }


}

OperationShape::~OperationShape() {
}

bool OperationShape::contains(const Point &p) const {
    switch(operationType){
        case INTERSECTION:
            return shape1.contains(p) && shape2.contains(p);
        break;

        case UNION:
            return shape1.contains(p) || shape2.contains(p);
        break;

        case SUBTRACTION:
            return shape1.contains(p) && !shape2.contains(p);
        break;     
    }
}

void draw() const {
        shape1->draw();
        shape2->draw();
}

std::vector<Point*> get_points(){
    std::vector<Point*> operationPoints;
    std::vector<Point*> points1 = shape1->get_points() ;
    std::vector<Point*> points2 = shape2->get_points();
    
    operationPoints.insert(operationPoints.end(), &points1[0], &points1[shape1->nbpointss1] );
    operationPoints.insert(operationPoints.end(), &points2[0], &points2[shape2->nbpointss2] );

    return operationPoints;
}


