#ifndef CONTOUR_H
#define CONTOUR_H

#include "image.h"

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

#endif
