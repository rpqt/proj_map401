#include "contour.h"
#include "robot.h"
#include "../TACHE2/geometrie2d.h"

bool trouve_pixel_depart(Image I, int *x_out, int *y_out)
{
	for (UINT y = 1; y < hauteur_image(I); y++) {
		for (UINT x = 1; x < largeur_image(I); x++) {
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

/* créer une cellule de liste avec l'élément v 
   renvoie le pointeur sur la cellule créée 
   la fonction s'arrete si la création n'a pas pu se faire */
Cellule *creer_cellule(Point p)
{
	Cellule *cel;
	cel = (Cellule *)malloc(sizeof(Cellule));
	if (cel == NULL){
		fprintf(stderr, "creer_cellule ; allocation impossible \n");
		exit(-1);
	}
	cel->data = p;
	cel->suivant = NULL;
	return cel;
}

/* créer une liste vide */
Sequence creer_sequence()
{
	Sequence s = {0, NULL, NULL};
	return s;
}

/* ajouter le point p en fin de la liste s, renvoie la liste s modifiée */
Sequence ajouter_point(Sequence *s, Point p)
{
	Cellule *cel;

	cel = creer_cellule(p);
	if (s->taille == 0)
	{
		/* premier élément de la liste */
		s->tete = cel;
		s->fin = cel;
	}
	else
	{
		s->fin->suivant = cel;
		s->fin = cel;
	}

	s->taille ++;
	return *s; 
}

/* suppression de tous les éléments de la liste, renvoie la liste s vide */
Sequence supprimer_sequence(Sequence s)
{
	Cellule *cel = s.tete; 

	while(cel)
	{
		Cellule *suivant = cel->suivant; 
		free (cel);
		cel = suivant;
	}
	s.tete = NULL;
	s.fin = NULL;
	s.taille = 0;
	return s;
}

/* concatène s2 à la suite de s1, renvoie la liste s1 modifiée */
Sequence concatener_sequences(Sequence s1, Sequence s2)
{
	/* cas où l'une des deux listes est vide */
	if (s1.taille == 0) return s2;
	if (s2.taille == 0) return s1;

	/* les deux listes sont non vides */
	s1.fin->suivant = s2.tete; /* lien entre s1.tete et s2.fin */
	s1.fin = s2.fin; /* le dernier élément de s1 est celui de s2 */
	s1.taille += s2.taille; /* nouvelle taille pour s1 */

	return s1;
}

/* créer une séquence de points sous forme d'un tableau de points
   à partir de la liste de points s */
Tableau_Point sequence_vers_tableau(Sequence s)
{
	Tableau_Point t; 

	/* taille de t = taille de s */
	t.taille = s.taille;

	/* allocation dynamique du tableau de Point */
	t.tab = malloc(sizeof(Point) * t.taille);
	if (t.tab == NULL)
	{
		/* allocation impossible : arret du programe avec un message */
		fprintf(stderr, "sequence_vers_tableau : allocation impossible\n");
		exit(-1);
	}

	/* remplir le tableau de points t en parcourant la liste s */
	int k = 0; /* indice de l'élément dans t.tab */
	Cellule *cel = s.tete; /* pointeur sur l'élément dans s */
	while (cel)
	{
		t.tab[k] = cel->data;
		k++;
		cel = cel->suivant; /* passer a l'élément suivant dans la liste chainée */
	}

	return t;
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

