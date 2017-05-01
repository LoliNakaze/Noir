/*=================================================================*/
/*= E.Incerti - incerti@upem.fr                                   =*/
/*= Université Paris-Est-Marne-la-Vallée                          =*/
/*= Exemple de fonctionalités de lib. graphique <g3x>             =*/
/*=================================================================*/

#include <g3x.h>
#include <cstdio>
#include "Shape.hpp"
#include "Sphere.hpp"
#include "Cone.hpp"
#include "Cylinder.hpp"
#include "Cube.hpp"
#include "Tore.h"
#include "ScaleShape.h"
#include "TranslationShape.h"
#include "RotationShape.h"
#include "OperationShape.hpp"

#define NBPOINTS 50000
#define NBSHAPE 9


std::vector<Shape *> shapes = std::vector<Shape *>(NBSHAPE);

static void Init(void) {


    // shapes[0] = new TranslationShape(Vector(5, 0, 0), new TranslationShape(Vector(2, 0, 0), new Sphere(NBPOINTS)));
    shapes[0] = new Sphere(NBPOINTS) ;
    shapes[1] = new TranslationShape(Vector(1,0,0) , new Cylinder(NBPOINTS) );
    shapes[2] = new TranslationShape(Vector(2,0,0) , new Cube(NBPOINTS) );
    shapes[3] = new TranslationShape(Vector(-1,0,0) , new Cone(NBPOINTS) );
    shapes[4] = new TranslationShape(Vector(-2,0,0) , new Tore(NBPOINTS) );
    shapes[5] =new RotationShape( 45.0, Vector(1,0,0) ,(new TranslationShape(Vector(-3,0,0) , new Tore(NBPOINTS) ))); 

    shapes[6] =new ScaleShape(Vector(2,2,2) ,(new TranslationShape(Vector(0,-3,0) , new Sphere(NBPOINTS) ))); 

    shapes[7] = new RotationShape( 45.0, Vector(1,0,0) ,(new TranslationShape(Vector(-1,-1,0) , new Cone(NBPOINTS) ))); 


    shapes[8] = new TranslationShape(Vector(1,2,0) , (new OperationShape(new Cube(NBPOINTS), new Cone(NBPOINTS), INTERSECTION)));


//    shapes[0] = new ScaleShape(Vector(2, 2, 2), new RotationShape(45., Vector(0, 1, 0), new Tore(NBPOINTS)));
}

/*= FONCTION D'ANIMATION =*/
static void Anim(void) {
    fprintf(stderr, "Anim-");
}

/*= FONCTION DE DESSIN PRINCIPALE =*/
static void Draw(void) {
    for (int i = 0; i < NBSHAPE; i++) {
        glPushMatrix();
        TransformationShape *tr_shape = dynamic_cast<TransformationShape *>(shapes[i]);
        if (tr_shape) {
            tr_shape->apply_transformation();
        }
        shapes[i]->draw();
        glPopMatrix();
    }
}

/*=    ACTION A EXECUTER EN SORTIE   =*/
/*= libération de mémoire, nettoyage =*/
/*= -> utilise la pile de <atexit()> =*/
static void Exit(void) {
    /* rien à faire ici puisqu'il n'y a pas d'allocation dynamique */
    for (int i = 0; i < 2; i++) {
        delete shapes[i];
    }
    fprintf(stderr, "\nbye !\n");
}


int main(int argc, char **argv) {
    /* initialisation de la fenêtre graphique et paramétrage Gl */
    g3x_InitWindow(*argv, 768, 512);

    /* définition des fonctions */
    g3x_SetInitFunction(Init);     /* la fonction de sortie */
    g3x_SetExitFunction(Exit);     /* la fonction de sortie */
    g3x_SetDrawFunction(Draw);     /* la fonction de Dessin */
    g3x_SetAnimFunction(Anim);

    /* boucle d'exécution principale */
    return g3x_MainStart();

    /* rien après ça */
}