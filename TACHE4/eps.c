#include "eps.h"

static const char *entete = "%!PS-Adboe-3.0 ESPF-3.0";
static const char *lineto = "lineto";
static const char *moveto = "moveto";

static void eps_ajoute_contour(FILE *f, Contour contour, int hauteur,
		char *mode_trace)
{
	for (Cellule *c = contour.tete; c != NULL; c = c->suivant) {
		fprintf(f, "%.1f %.1f %s ", c->data.x, hauteur - c->data.y,
			c == contour.tete ? moveto : lineto);
	}
	fprintf(f, "%s ", mode_trace);
}

int eps_ecrire_contour(FILE *f, Contour contour, int largeur, int hauteur,
		       char *mode_trace)
{
	if (!f) {
		return 0;
	}

	/* En-tête */
	fprintf(f, "%s\n", entete);

	/* Boîte englobante */
	fprintf(f, "%%BoundingBox %d %d %d %d\n", 0, 0, largeur, hauteur);

	eps_ajoute_contour(f, contour, hauteur, mode_trace);

	/* Showpage */
	fprintf(f, "showpage\n");

	return 1;
}
