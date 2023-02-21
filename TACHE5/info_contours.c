#include "contour.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	if (argc != 3) {
		printf("Usage: %s <image.pbm> <sortie.contours>\n", argv[0]);
		exit(1);
	}

	Image I = lire_fichier_image(argv[1]);

	Sequence contours = image_vers_contours(I);

	FILE *fichier_contours = fopen(argv[2], "w");
	if (!fichier_contours) {
		fprintf(fichier_contours,
			"Erreur durant l'ouverture du fichier"
			" %s en écriture.\n",
			argv[2]);
		exit(1);
		perror(argv[2]);
	}

	ecrire_fichier_contours(fichier_contours, contours);

	int nb_points = 0;
	for (Cellule *ctr = contours.tete; ctr != NULL; ctr = ctr->suivant) {
		nb_points += ctr->contour.taille;
	}

	int nb_contours = contours.taille;
	int nb_segments = nb_points - nb_contours;
	printf("%d contours, %d segments\n", nb_contours, nb_segments);

	supprimer_sequence(contours);
	supprimer_image(&I);

	exit(0);
}
