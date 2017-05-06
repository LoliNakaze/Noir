/*=================================================================*/
/*= E.Incerti - incerti@upem.fr                                   =*/
/*= Université Paris-Est-Marne-la-Vallée                          =*/
/*= Exemple de fonctionalités de lib. graphique <g3x>             =*/
/*=================================================================*/

#include <g3x.h>
#include <cstdio>
#include <stdio.h>
#include <iostream>
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

#define NBPOINTS 100000
#define NBSHAPE 1

int sceneNumber = 1;


std::vector<Shape *> shapes = std::vector<Shape *>(NBSHAPE);

static void Init(void) {
    Shape *init1;
    switch (sceneNumber) {
        case 1:
            init1 = new ScaleShape(Vector(0.1, 0.1, 0.8),
                                          new Cube(NBPOINTS, Vector(255, 255, 0)));

            shapes[0] =
                    new RotationShape(45.0, Vector(1, 0, 0), new OperationShape(
                            new OperationShape(
                                    new OperationShape(new TranslationShape(Vector(15, 10, -1), init1),
                                                       new TranslationShape(Vector(15, -10, -1), init1),
                                                       UNION),
                                    new OperationShape(new TranslationShape(Vector(-15, -10, -1), init1),
                                                       new TranslationShape(Vector(-15, 10, -1), init1),
                                                       UNION),
                                    UNION),
                            new OperationShape(
                                    new ScaleShape(Vector(2, 1.5, 0.1), new Cube(NBPOINTS, Vector(255, 255, 0))),
                                    new TranslationShape(Vector(0, 0, 2),
                                                         new ScaleShape(Vector(0.1, 0.1, 0.1),
                                                                        new Sphere(NBPOINTS, Vector(255, 0, 0)))),
                                    UNION), UNION));
            break;
        case 2:
            shapes[0] = new Cone(NBPOINTS, Vector(255, 0, 0));

            break;
        case 3:
            shapes[0] = new Cube(NBPOINTS, Vector(255, 0, 0));

            break;
        default:
            shapes[0] = new Sphere(NBPOINTS, Vector(255, 0, 0));
            break;

    }


    // shapes[0] = new TranslationShape(Vector(5, 0, 0), new TranslationShape(Vector(2, 0, 0), new Sphere(NBPOINTS)));
//    shapes[0] = new Sphere(NBPOINTS);
//    shapes[1] = new TranslationShape(Vector(2, 0, 0), new Cylinder(NBPOINTS));
//    shapes[2] = new TranslationShape(Vector(4, 0, 0), new Cube(NBPOINTS));
//    shapes[3] = new TranslationShape(Vector(-2, 0, 0), new Cone(NBPOINTS));
//    shapes[4] = new TranslationShape(Vector(-4, 0, 0), new Tore(NBPOINTS));
//    shapes[5] = new RotationShape(45.0, Vector(2, 0, 0), (new TranslationShape(Vector(-6, 0, 0), new Tore(NBPOINTS))));
//
//    shapes[6] = new ScaleShape(Vector(2, 2, 2), (new TranslationShape(Vector(0, -6, 0), new Sphere(NBPOINTS))));
//
//    shapes[7] = new RotationShape(45.0, Vector(2, 0, 0), (new TranslationShape(Vector(-2, -2, 0), new Cone(NBPOINTS))));
//    shapes[0] =
//            new RotationShape(45.0, Vector(1, 0, 0), new OperationShape(
//                    new OperationShape(
//                            new OperationShape(new TranslationShape(Vector(15, 10, -1),
//                                                                    new ScaleShape(Vector(0.1, 0.1, 0.8),
//                                                                                   new Cube(NBPOINTS))),
//                                               new TranslationShape(Vector(15, -10, -1),
//                                                                    new ScaleShape(Vector(0.1, 0.1, 0.8),
//                                                                                   new Cube(NBPOINTS))), UNION),
//                            new OperationShape(new TranslationShape(Vector(-15, -10, -1),
//                                                                    new ScaleShape(Vector(0.1, 0.1, 0.8),
//                                                                                   new Cube(NBPOINTS))),
//                                               new TranslationShape(Vector(-15, 10, -1),
//                                                                    new ScaleShape(Vector(0.1, 0.1, 0.8),
//                                                                                   new Cube(NBPOINTS))), UNION),
//                            UNION),
//                    new OperationShape(new ScaleShape(Vector(2, 1.5, 0.1), new Cube(NBPOINTS)),
//                                       new TranslationShape(Vector(0, 0, 2),
//                                                            new ScaleShape(Vector(0.1, 0.1, 0.1),
//                                                                           new Sphere(NBPOINTS))),
//                                       UNION), UNION));
//    Shape *shape = new OperationShape(new ScaleShape(Vector(1, 1, 0.1), new Cylinder(NBPOINTS)),
//                                      new ScaleShape(Vector(0.9, 0.9, 0.9), new Cone(NBPOINTS)), UNION);
//    shapes[0] = new OperationShape(shape, new TranslationShape(Vector(0, 0, -3),
//                new RotationShape(180, Vector(1, 0, 0), shape)), UNION);
//    shapes[0] = new OperationShape(new Cube(NBPOINTS), new ScaleShape(Vector(1.5, 1.5, 1.5), new Sphere(NBPOINTS)),
//                                   SUBTRACTION);
//    shapes[2] = new Cube(NBPOINTS);

//    shapes[0] = new ScaleShape(Vector(4, 4, 4), new RotationShape(45., Vector(0, 1 2, 0), new Tore(NBPOINTS)));
}

/*= FONCTION D'ANIMATION =*/
static void Anim(void) {
    fprintf(stderr, "Anim-");
}

/*= FONCTION DE DESSIN PRINCIPALE =*/
static void Draw(void) {
    for (int i = 0; i < NBSHAPE; i++) {
//        std::cout << shapes[i]->contains(Vector(2, 0, 0)) << std::endl;
        shapes[i]->draw();
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

static void usage() {
    printf("USAGE: ./project  SCENENUMBER\n");
}

int main(int argc, char **argv) {
    if (argc != 2) {
        usage();
        return 0;
    }
    sceneNumber = atoi(argv[1]);

//    std::cout << argc << std::endl;

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