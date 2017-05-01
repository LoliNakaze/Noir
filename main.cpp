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
#define NBSHAPE 1

std::vector<Shape *> shapes = std::vector<Shape *>(NBSHAPE);

static void Init(void) {

//     shapes[0] = new Sphere(NBPOINTS);
//    shapes[0] = new Cylinder(NBPOINTS);
//      shapes[0] = new Cube(NBPOINTS);
//    shapes[0] = new Cone(NBPOINTS);
    shapes[0] = new OperationShape(new Cylinder(NBPOINTS), new Cube(NBPOINTS), INTERSECTION);
//    shapes[0] = new ScaleShape(Vector(2, 2, 2), new RotationShape(45., Vector(0, 1, 0), new Tore(NBPOINTS)));
}

/*= FONCTION D'ANIMATION =*/
static void Anim(void) {
    fprintf(stderr, "Anim-");
}

/*= FONCTION DE DESSIN PRINCIPALE =*/
static void Draw(void) {
    for (int i = 0; i < NBSHAPE; i++) {
/*        Shape* origin = shapes[i];
        TransformationShape *tr_shape = dynamic_cast<TransformationShape *>(shapes[i]);
        if (tr_shape) {
            origin = tr_shape->origin_shape();
        }

        G3Xpoint point = {2, 0, 0};
        G3Xpoint res = {0, 0, 0};
        g3x_ProdHMatPoint(origin->matrice_transformation_inverse, point, res);
        std::cerr << shapes[i]->contains(Point(res[0], res[1], res[2])) << std::endl; */
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