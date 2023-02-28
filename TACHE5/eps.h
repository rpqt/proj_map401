#ifndef EPS_H
#define EPS_H

#include "contour.h"

int eps_ecrire_contours(FILE *f, Sequence contours, int largeur, int hauteur,
		char *mode_trace);

#endif
