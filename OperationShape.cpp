#include "OperationShape.hpp"
#include <iostream>
#include <math.h>

OperationShape::OperationShape(Shape* s1, Shape* s2, OperationType ot ) {

    shape1 = s1;
    shape2 = s2;
    operationType = op;

    switch(ot){
        case INTERSECTION:
            toutLesPointss2 = s2.getPoints();

            for(int i = 0 ; i < s2.nbpoint ; i++){

                if( s1.contains(     toutLesPointss2[i] * s1.matrice_transformation_inverse  ){
                    toutLesPointss2[i].visibility = true;
                }
                else{
                    toutLesPointss2[i].visibility = false;
                }    

            }

            toutLesPointss1 = s2.getPoints();

            for(int i = 0 ; i < s1.nbpoint ; i++){

                if( s2.contains(     toutLesPointss1[i] * s2.matrice_transformation_inverse  ){
                    toutLesPointss1[i].visibility = true;
                }
                else{
                    toutLesPointss1[i].visibility = false;
                }    

            }



        break;
        case UNION:
           toutLesPointss2 = s2.getPoints();

            for(int i = 0 ; i < s2.nbpoint ; i++){

                if( s1.contains(     toutLesPointss2[i] * s1.matrice_transformation_inverse  ){
                    toutLesPointss2[i].visibility = false;
                }
                else{
                    toutLesPointss2[i].visibility = true;
                }    

            }

            toutLesPointss1 = s2.getPoints();

            for(int i = 0 ; i < s1.nbpoint ; i++){

                if( s2.contains(     toutLesPointss1[i] * s2.matrice_transformation_inverse  ){
                    toutLesPointss1[i].visibility = false;
                }
                else{
                    toutLesPointss1[i].visibility = true;
                }    

            }

        break;

        case SUBTRACTION:
           toutLesPointss2 = s2.getPoints();
            for(int i = 0 ; i < s2.nbpoint ; i++){
                toutLesPointss2[i].visibility = false;   
            }

            toutLesPointss1 = s2.getPoints();

            for(int i = 0 ; i < s1.nbpoint ; i++){
                if( s2.contains(     toutLesPointss1[i] * s2.matrice_transformation_inverse  ){
                    toutLesPointss1[i].visibility = false;
                }
                else{
                    toutLesPointss1[i].visibility = true;
                }    
            }

        break;

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

std::vector<Point*> getPoints(){
    std::vector<Point*> operationPoints;
    std::vector<Point*> points1 = shape1.getPoints() ;
    std::vector<Point*> points2 = shape2.getPoints();
    
    operationPoints.insert(operationPoints.end(), &points1[0], &points1[nbpoints1] );
    operationPoints.insert(operationPoints.end(), &points2[0], &points2[nbpoints2] );

    return operationPoints;
}


