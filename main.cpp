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


int sceneNumber = 1;
int nbShape = 1;


std::vector<Shape *> shapes = std::vector<Shape *>(5);

static void Init(void) {
    Shape *init1;
    Shape *ears, *eyes;
    Shape *aile1;
    Shape *aile2;
    Shape *lien;
    Shape *ailes;
    Shape *centre;
    Shape *cockpit;
    switch (sceneNumber) {
        case 1:
            nbShape = 1;
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
            ears = new OperationShape(
                    new TranslationShape(Vector(0, 0, -0.35), new ScaleShape(Vector(0.37, 0.37, 0.1),
                                                                             new RotationShape(90, Vector(1, 0, 0),
                                                                                               new Cylinder(NBPOINTS,
                                                                                                            Vector(255,
                                                                                                                   255,
                                                                                                                   200))))),
                    new ScaleShape(Vector(0.35, 0.35, 0.1),
                                   new RotationShape(90, Vector(1, 0, 0), new Cylinder(NBPOINTS, Vector(0, 0, 255)))),
                    UNION);

            eyes = new ScaleShape(Vector(0.20, 0.1, 0.30), new Sphere(NBPOINTS, Vector(255, 255, 255)));
            shapes[0] = new OperationShape(
                    new OperationShape(
                            new OperationShape(
                                    new TranslationShape(Vector(0, 0.625, -0.83),
                                                         new OperationShape(new ScaleShape(Vector(0.8, 0.8, 0.8),
                                                                                           new Sphere(NBPOINTS,
                                                                                                      Vector(255,
                                                                                                             255,
                                                                                                             200))),
                                                                            new TranslationShape(Vector(0, 2.5, 0),
                                                                                                 new ScaleShape(
                                                                                                         Vector(0.3,
                                                                                                                0.3,
                                                                                                                0.3),
                                                                                                         new Sphere(
                                                                                                                 NBPOINTS /
                                                                                                                 2,
                                                                                                                 Vector(0,
                                                                                                                        0,
                                                                                                                        0)))),
                                                                            UNION)),
                                    new ScaleShape(Vector(0.8, 0.8, 1.2), new Sphere(NBPOINTS, Vector(0, 0, 255))),
                                    UNION),
                            new OperationShape(
                                    new TranslationShape(Vector(0.8, 0, 1), ears),
                                    new TranslationShape(Vector(-0.8, 0, 1), ears),
                                    UNION
                            ),
                            UNION),
                    new OperationShape(
                            new TranslationShape(Vector(1, 7, 1.2), eyes),
                            new TranslationShape(Vector(-1, 7, 1.2), eyes),
                            UNION
                    ),
                    UNION);
            break;
        case 3:
            nbShape = 4;

            aile1 = new ScaleShape(Vector(0.01, 1, 1),
                                   new TranslationShape(Vector(0.75, 0, 0), new Cube(NBPOINTS, Vector(255, 0, 0))));
            aile2 = new ScaleShape(Vector(0.01, 1, 1),
                                   new TranslationShape(Vector(-0.75, 0, 0), new Cube(NBPOINTS, Vector(255, 0, 0))));
            cockpit = new ScaleShape(Vector(0.3, 0.3, 0.3), new Sphere(NBPOINTS, Vector(255, 0, 0)));
            lien = new ScaleShape(Vector(0.05, 0.05, 0.75),
                                  new RotationShape(90.0, Vector(0, 1, 0), new Cylinder(NBPOINTS, Vector(0, 255, 0))));

            shapes[0] = cockpit;
            shapes[1] = aile1;
            shapes[2] = aile2;
            shapes[3] = lien;
            break;
        case 4:
            nbShape = 5;

            shapes[0] = new Sphere(NBPOINTS, Vector(255, 0, 0));
            shapes[1] = new TranslationShape(Vector(2, 2, 0), new Cube(NBPOINTS, Vector(0, 255, 0)));
            shapes[2] = new TranslationShape(Vector(2, -2, 0), new Cylinder(NBPOINTS, Vector(0, 0, 255)));
            shapes[3] = new TranslationShape(Vector(-2, 2, 0), new Cone(NBPOINTS, Vector(0, 255, 255)));
            shapes[4] = new TranslationShape(Vector(-2, -2, 0), new Tore(NBPOINTS, Vector(255, 255, 0)));
            break;
        case 5:
            nbShape = 3;
            shapes[0] = new OperationShape(
                    new Sphere(NBPOINTS, Vector(255, 255, 200)),
                    new TranslationShape(Vector(0.3, 0, 0), new Sphere(NBPOINTS, Vector(255, 255, 0))),
                    SUBTRACTION
            );

            shapes[1] = new TranslationShape(Vector(2, 2, 0),
                                             new OperationShape(
                                                     new Sphere(NBPOINTS, Vector(255, 0, 255)),
                                                     new Cone(NBPOINTS, Vector(255, 0, 255)),
                                                     INTERSECTION
                                             ));
            shapes[2] = new TranslationShape(Vector(2, -2, 0),
                                             new OperationShape(
                                                     new Cube(NBPOINTS, Vector(255, 255, 255)),
                                                     new ScaleShape(Vector(1.2, 1.2, 1.2),
                                                                    new Sphere(NBPOINTS, Vector(255, 0, 0))),
                                                     UNION
                                             )
            );
            break;
        default:
            shapes[0] = new Sphere(NBPOINTS, Vector(255, 0, 0));
            break;

    }


}

/*= FONCTION D'ANIMATION =*/
static void Anim(void) {
    fprintf(stderr, "Anim-");
}

/*= FONCTION DE DESSIN PRINCIPALE =*/
static void Draw(void) {
    for (int i = 0; i < nbShape; i++) {
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