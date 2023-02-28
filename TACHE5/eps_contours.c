#include "../TACHE1/image.h"
#include "eps.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void usage(int argc, char **argv)
{
	printf("Usage: %s <image.pbm> <sortie.eps> [mode_tracé]\n", argv[0]);
	printf("mode_tracé: fill | stroke\n");
}

int main(int argc, char **argv)
{
	if (argc < 3) {
		usage(argc, argv);
	}

	char *mode_trace = "fill";
	if (argc >= 4) {
		mode_trace = argv[3];
		if (strncmp("fill", mode_trace, 5) &&
		    strncmp("stroke", mode_trace, 5)) {
			printf("mode_trace invalide\n");
			usage(argc, argv);
			exit(1);
		}
	}

	/* Ouvre l'image donnée en premier argument. */
	Image I = lire_fichier_image(argv[1]);
	UINT L = largeur_image(I);
	UINT H = hauteur_image(I);

	/* Extrait les contours de l'image. */
	Sequence contours = image_vers_contours(I);

	supprimer_image(&I);

	/* 
	 * Ouvre le fichier EPS sortie dont le nom est
	 * donné en deuxième argument.
	 */
	char *nom_sortie = argv[2];
	FILE *fout = fopen(nom_sortie, "w");
	if (!fout) {
		fprintf(stderr, "impossible d'ouvrir %s en écriture:\n",
			nom_sortie);
		perror(nom_sortie);
		exit(1);
	}

	/* Écrit les contours dans le fichier sortie. */
	eps_ecrire_contours(fout, contours, L, H, mode_trace);
	fclose(fout);

	/* Calcule et affiche des statistiques sur les contours. */
	int nb_points = 0;
	for (Cellule *ctr = contours.tete; ctr != NULL; ctr = ctr->suivant) {
		nb_points += ctr->contour.taille;
	}

	int nb_contours = contours.taille;
	int nb_segments = nb_points - nb_contours;
	printf("%d contours, %d segments\n", nb_contours, nb_segments);

	supprimer_sequence(contours);

	exit(0);
}
