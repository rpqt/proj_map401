#include "../TACHE1/image.h"
#include "../TACHE2/geometrie2d.h"
#include "contour.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	if (argc != 3) {
		printf("usage: %s <fichier_entree.pbm>"
		       " <fichier_sortie.contours>\n",
		       argv[0]);
		exit(1);
	}

	Image I = lire_fichier_image(argv[1]);

	int x_initial, y_initial;
	if (!trouve_pixel_depart(I, &x_initial, &y_initial)) {
		printf("Aucun contour trouvé dans l'image !\n");
		exit(1);
	}

	Sequence seq = image_vers_contour(I, x_initial - 1, y_initial - 1);

	FILE *fichier_contours = fopen(argv[2], "w");
	if (!fichier_contours) {
		fprintf(stderr,
			"impossible d'ouvrir le fichier %s"
			" en écriture\n",
			argv[2]);
		perror(argv[2]);
		exit(1);
	}

	ecrire_fichier_contour(fichier_contours, seq);
	fclose(fichier_contours);

	printf("L'image est de dimension %dx%d.\n", largeur_image(I),
	       hauteur_image(I));
	printf("Le contour contient %d segments.\n", seq.taille - 1);

	/// XXX: cleanup seq, I
	exit(0);
}
