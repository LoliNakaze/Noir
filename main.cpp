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

#define NBPOINTS 50000
#define NBSHAPE 1


std::vector<Shape *> shapes = std::vector<Shape *>(NBSHAPE);

static void Init(void) {
//    shapes[0] = new Cone(NBPOINTS);
//    shapes[1] = new Cylinder(NBPOINTS);
//    shapes[2] = new Cube(NBPOINTS);
//    shapes[3] = new Cone(NBPOINTS);
    shapes[0] = new Tore(NBPOINTS);
}

/*= FONCTION D'ANIMATION =*/
static void Anim(void) {
    fprintf(stderr, "Anim-");
}

/*= FONCTION DE DESSIN PRINCIPALE =*/
static void Draw(void) {

    for (int i = 0 ; i < NBSHAPE ; i++) {
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