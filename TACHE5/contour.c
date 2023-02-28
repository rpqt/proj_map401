#include "contour.h"
#include "../TACHE3/robot.h"
#include "sequence.h"
#include "../TACHE3/image.h"

Image image_vers_masque(Image I)
{
	UINT hauteur = hauteur_image(I);
	UINT largeur = largeur_image(I);

	Image M = creer_image(largeur, hauteur);

	for (UINT y = 1; y <= hauteur; y++) {
		for (UINT x = 1; x <= largeur; x++) {
			/* Pour chaque pixel noir avec son voisin N blanc
			   on ajoute un pixel noir dans M */
			if (get_pixel_image(I, x, y) == NOIR &&
			    get_pixel_image(I, x, y - 1) == BLANC) {
				set_pixel_image(M, x, y, NOIR);
			}
		}
	}
	return M;
}

bool trouve_pixel_depart(Image I, int *x_out, int *y_out)
{
	UINT hauteur = hauteur_image(I);
	UINT largeur = largeur_image(I);
	for (UINT y = y_out; y <= hauteur; y++) {
		for (UINT x = x_out; x <= largeur; x++) {
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
void affiche_contour(Contour s)
{
	Tableau_Point tp = contour_vers_tableau(s);
	int k;
	int nP = tp.taille;
	printf("%d points : [", nP);
	for (k = 0; k < nP; k++) {
		Point P = tp.tab[k]; /* récupérer le point d'indice k */
		printf(" (%5.1f, %5.1f)", P.x, P.y);
	}
	printf("]\n");

	free(tp.tab); /* supprimer le tableau de point tp */
}

/* retourne un contour sous forme de liste chainée
   prend une image et les coordonées de départ du robot */
Contour image_vers_contour(Image I, int x_initial, int y_initial)
{
	Robot r = creer_robot(x_initial, y_initial);
	Contour c = creer_contour();

	/* la boucle s'exécute tant que le robot n'est pas revenu
	   à sa position initiale. */
	do {
		Point p = set_point(r.x, r.y);
		ajouter_point(&c, p);
		avancer_robot(&r);
		orienter_robot(&r, I);
	} while (r.x != x_initial || r.y != y_initial || r.o != EST);

	ajouter_point(&c, set_point(r.x, r.y));

	return c;
}

Contour masque_vers_contour(Image I, Image M, int x_initial, int y_initial)
{
	Robot r = creer_robot(x_initial, y_initial);
	Contour c = creer_contour();

	/* la boucle s'exécute tant que le robot n'est pas revenu
	   à sa position initiale. */
	do {
		Point p = set_point(r.x, r.y);
		ajouter_point(&c, p);
		/* on vérifie l'orientation du robot pour modifier le masque M */
		if (r.o == EST) set_pixel_image(M, r.x+1, r.y+1, BLANC);

		avancer_robot(&r);
		orienter_robot(&r, I);
	} while (r.x != x_initial || r.y != y_initial || r.o != EST);

	ajouter_point(&c, set_point(r.x, r.y));

	return c;
}

Sequence image_vers_contours(Image I)
{
	Sequence s = creer_sequence();
	Image M = image_vers_masque(I);

	int x = 1;
	int y = 1;

	while (trouve_pixel_depart(M, &x, &y))
	{
		Contour c = masque_vers_contour(I, M, x-1, y-1);
		ajouter_contour(&s, c);
	}

	return s;
}

void ecrire_contour(FILE *f, Contour s)
{
	if (s.taille == 0) {
		fprintf(stderr, "Attention contour vide");
		return;
	}
	fprintf(f, "%d\n", s.taille);
	CelluleContour *cel = s.tete;
	while (cel) {
		fprintf(f, " %.1f %.1f\n", cel->data.x, cel->data.y);
		cel = cel->suivant;
	}
}

void ecrire_fichier_contours(FILE *f, Sequence seq)
{
	fprintf(f, "%d\n\n", seq.taille);
	for (Cellule *cel = seq.tete; cel != NULL; cel = cel->suivant) {
		ecrire_contour(f, cel->contour);
	};
}
