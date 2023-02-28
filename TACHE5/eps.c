#include "eps.h"

static const char *entete = "%!PS-Adboe-3.0 ESPF-3.0";
static const char *lineto = "lineto";
static const char *moveto = "moveto";

static void eps_ajoute_contour(FILE *f, Contour contour, int hauteur)
{
	for (CelluleContour *c = contour.tete; c != NULL; c = c->suivant) {
		fprintf(f, "%.1f %.1f %s\n", c->data.x, hauteur - c->data.y,
			c == contour.tete ? moveto : lineto);
	}
}

int eps_ecrire_contours(FILE *f, Sequence contours, int largeur, int hauteur,
			char *mode_trace)
{
	if (!f) {
		return 0;
	}

	/* En-tête */
	fprintf(f, "%s\n", entete);

	/* Boîte englobante */
	fprintf(f, "%%%%BoundingBox: %d %d %d %d\n", 0, 0, largeur, hauteur);

	for (Cellule *cel = contours.tete; cel != NULL; cel = cel->suivant) {
		eps_ajoute_contour(f, cel->contour, hauteur);
	}

	fprintf(f, "%s\n", mode_trace);

	/* Showpage */
	fprintf(f, "showpage\n");

	return 1;
}
