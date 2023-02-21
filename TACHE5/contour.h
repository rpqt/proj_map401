#ifndef CONTOUR_H
#define CONTOUR_H

#include "../TACHE1/image.h"
#include "sequence.h"

/*
 * Cherche un pixel de départ pour un contour dans l'image donnée.
 * Si un pixel satisfait les conditions, retourne true et écrit ses coordonnées
 * dans [x_out] et [y_out].
 * Sinon retourne false.
 */
bool trouve_pixel_depart(Image I, int *x_out, int *y_out);

/*
 * Affiche le contour partant du [point_initial] donné dans l'image [I]
 * sur la sortie standard.
 */
void affiche_contour_a_la_volee(Image I, int x_initial, int y_initial);

/* affiche le contour s à l'écran
   cette fonction montre un exemple de conversion d'une liste de points en
   tableau de points afin de pouvoir par la suite accéder aux éléments d'une
   séquence de points par indice */
void affiche_contour(Contour s);

/* retourne un contour sous forme de liste chainée
   prend une image et les coordonées de départ du robot */
Contour image_vers_contour(Image I, int x_initial, int y_initial);

Sequence image_vers_contours(Image I);

/*
 * Écrit, dans le fichier donné, le nombre de points d'un contour,
 * suivi des coordonnées de chaque point.
 */
void ecrire_contour(FILE *f, Contour s);

/*
 * Écrit la séquence de contours dans le fichier donné avec le format
 * décrit dans la tâche 3:
 * - Une ligne avec le nombre de contours
 * - Pour chaque contour, le nombre de points qui le composent,
 *   suivi des coordonnées de ces points dans l'ordre.
 */
void ecrire_fichier_contours(FILE *f, Sequence s);

#endif
