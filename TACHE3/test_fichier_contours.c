#include "../TACHE1/image.h"
#include "../TACHE2/geometrie2d.h"
#include "contour.h"
#include <stdio.h>
#include <stdlib.h>

void affiche_usage(char **argv)
{
	printf("usage: %s <image_entree.pbm>"
	       " <fichier_sortie.contours>\n",
	       argv[0]);
}

int main(int argc, char **argv)
{
	if (argc != 3) {
		affiche_usage(argv);
		exit(1);
	}

	/* Ouverture de l'image d'entrée */
	Image I = lire_fichier_image(argv[1]);

	int x_initial, y_initial;
	if (!trouve_pixel_depart(I, &x_initial, &y_initial)) {
		printf("Aucun contour trouvé dans l'image !\n"
		       " L'image est est-elle vide ?\n");
		exit(1);
	}

	Sequence seq = image_vers_contour(I, x_initial - 1, y_initial - 1);

	/* Ouverture du fichier contour (sortie) */
	FILE *fichier_contours = fopen(argv[2], "w");
	if (!fichier_contours) {
		fprintf(stderr,
			"Impossible d'ouvrir le fichier %s"
			" en écriture:\n",
			argv[2]);
		perror(argv[2]);
		exit(1);
	}

	ecrire_fichier_contour(fichier_contours, seq);
	fclose(fichier_contours);

	/* Affiche le nombre de segments et les dimensions. */
	printf("L'image est de dimension %dx%d.\n", largeur_image(I),
	       hauteur_image(I));
	printf("Le contour contient %d segments.\n", seq.taille - 1);

	supprimer_image(&I);
	supprimer_sequence(seq);
	exit(0);
}
