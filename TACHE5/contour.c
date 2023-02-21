#include "contour.h"
#include "../TACHE3/robot.h"
#include "sequence.h"

bool trouve_pixel_depart(Image I, int *x_out, int *y_out)
{
	UINT hauteur = hauteur_image(I);
	UINT largeur = largeur_image(I);
	for (UINT y = 1; y < hauteur; y++) {
		for (UINT x = 1; x < largeur; x++) {
			/*
			 * On arrête dès qu'on trouve un pixel noir
			 * avec un pixel blanc au dessus
			 */
			if (get_pixel_image(I, x, y) == NOIR &&
			    get_pixel_image(I, x, y - 1) == BLANC) {
				*x_out = x;
				*y_out = y;
				return true;
			}
		}
	}
	return false;
}

void affiche_contour_a_la_volee(Image I, int x_initial, int y_initial)
{
	Robot r = creer_robot(x_initial, y_initial);

	/*
	 * La boucle s'exécute tant que le robot n'est pas revenu
	 * à sa position initiale.
	 */
	do {
		printf("(%d,%d)\n", r.x, r.y);
		avancer_robot(&r);
		orienter_robot(&r, I);
	} while (r.x != x_initial || r.y != y_initial || r.o != EST);

	printf("(%d,%d)\n", r.x, r.y);
}


/* écrire le contour s à l'écran
   cette fonction montre un exemple de conversion d'une liste de points en
   tableau de points afin de pouvoir par la suite accéder aux éléments d'une
   séquence de points par indice */
void affiche_contour(Sequence s)
{
	Tableau_Point tp = sequence_vers_tableau(s);
	int k;
	int nP = tp.taille;
	printf("%d points : [", nP);
	for (k=0; k < nP; k++)
	{
		Point P = tp.tab[k]; /* récupérer le point d'indice k */
		printf(" (%5.1f, %5.1f)", P.x, P.y);
	}
	printf("]\n");

	free(tp.tab); /* supprimer le tableau de point tp */ 
}

/* retourne un contour sous forme de liste chainée 
   prend une image et les coordonées de départ du robot */
Sequence image_vers_contour(Image I, int x_initial, int y_initial)
{
	Robot r = creer_robot(x_initial, y_initial);
	Sequence s = creer_sequence();

	/*
	 * La boucle s'exécute tant que le robot n'est pas revenu
	 * à sa position initiale.
	 */
	do {
		Point p = set_point(r.x, r.y);
		ajouter_point(&s, p);
		avancer_robot(&r);
		orienter_robot(&r, I);
	} while (r.x != x_initial || r.y != y_initial || r.o != EST);

	ajouter_point(&s,set_point(r.x, r.y));

	return s;
}

/* écrit le nombre de points du contour suivi par la liste de points */
void ecrire_contour(FILE *f, Sequence s)
{
	if(s.taille == 0) 
	{
		fprintf(stderr, "Attention contour vide");
		return;
	}
	fprintf(f, "%d\n", s.taille);
	Cellule *cel = s.tete;
	while (cel)
	{
		fprintf(f, " %.1f %.1f\n", cel->data.x, cel->data.y);
		cel = cel->suivant;
	}

}

/* écrit plusieurs contours précédés du nombre de contours */
void ecrire_fichier_contour(FILE *f, Sequence s)
{
	fprintf(f, "%s", "1\n\n");
	ecrire_contour(f, s);
}

