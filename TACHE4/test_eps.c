#include "eps.h"
#include "../TACHE1/image.h"
#include "../TACHE3/contour.h"
#include <string.h>

int main(int argc, char **argv)
{
	if (argc < 2) {
		printf("usage: %s <image.pbm> [stroke|fill]\n", argv[0]);
		exit(1);
	}

	Image I = lire_fichier_image(argv[1]);

	int x_init, y_init;
	if (!trouve_pixel_depart(I, &x_init, &y_init)) {
		printf("Pas de contour detecté\n");
		exit(1);
	}

	Contour contour = image_vers_contour(I, x_init-1, y_init-1);

	char *mode_trace = "fill";
	if (argc >= 3) {
		mode_trace = argv[2];
	}

	if (strcmp(mode_trace, "stroke") && strcmp(mode_trace, "fill")) {
		printf("Mode de tracé invalide ! Utiliser stroke ou fill\n");
		printf("usage: %s <image.pbm> [stroke|fill]\n", argv[0]);
		exit(1);
	}

	eps_ecrire_contour(stdout, contour, largeur_image(I), hauteur_image(I),
		mode_trace);

	exit(0);
}
