//
// Created by nakaze on 01/05/17.
//

#ifndef PROJECT_TRANSLATIONSHAPE_H
#define PROJECT_TRANSLATIONSHAPE_H

#include <g3x.h>
#include "TransformationShape.h"

class TranslationShape : public TransformationShape {
public:
    TranslationShape(const Vector translation, Shape* shape);

    ~TranslationShape();

    void apply_itransformation() const;

    void apply_transformation() const;

private:
    const Vector tr_vector;
};


#endif //PROJECT_TRANSLATIONSHAPE_H
