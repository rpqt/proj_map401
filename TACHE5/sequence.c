#include "Contour.h"
#include "sequence.h"
#include <stdlib.h>
#include <stdio.h>

/* créer une CelluleContour de liste avec le point p 
   renvoie le pointeur sur la CelluleContour créée 
   la fonction s'arrete si la création n'a pas pu se faire */
CelluleContour *creer_CelluleContour(Point p)
{
	CelluleContour *cel;
	cel = (CelluleContour *)malloc(sizeof(CelluleContour));
	if (cel == NULL){
		fprintf(stderr, "creer_CelluleContour ; allocation impossible \n");
		exit(-1);
	}
	cel->data = p;
	cel->suivant = NULL;
	return cel;
}

/* créer une Cellule de liste avec le contour c
   renvoie le pointeur sur la CelluleContour créée 
   la fonction s'arrete si la création n'a pas pu se faire */
Cellule *creer_Cellule(Contour c)
{
	Cellule *cel;
	cel = (Cellule *)malloc(sizeof(Cellule));
	if (cel == NULL){
		fprintf(stderr, "creer_Cellule ; allocation impossible \n");
		exit(-1);
	}
	cel->contour = c;
	cel->suivant = NULL;
	return cel;
}

/* créer un contour vide */
Contour creer_Contour()
{
	Contour s = {0, NULL, NULL};
	return s;
}

/* créer une sequence vide */
Sequence creer_Sequence()
{
	Sequence s = {0, NULL, NULL};
	return s;
}

/* ajoute le point p en fin du contour c, renvoie le contour c modifiée */
Contour ajouter_point(Contour *c, Point p)
{
	CelluleContour *cel;

	cel = creer_CelluleContour(p);
	if (c->taille == 0)
	{
		/* premier élément de la liste */
		c->tete = cel;
		c->fin = cel;
	}
	else
	{
		c->fin->suivant = cel;
		c->fin = cel;
	}

	c->taille ++;
	return *c; 
}

/* ajoute le contour c en fin de la sequence s, renvoie la sequence s modifiée */
Sequence ajouter_contour(Sequence *s, Contour c)
{
	Cellule *cel;

	cel = creer_Cellule(c);
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

/* suppression de tous les éléments du contour, renvoie le contour c vide */
Contour supprimer_Contour(Contour c)
{
	CelluleContour *cel = c.tete; 

	while(cel)
	{
		CelluleContour *suivant = cel->suivant; 
		free (cel);
		cel = suivant;
	}
	c.tete = NULL;
	c.fin = NULL;
	c.taille = 0;
	return c;
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
Contour concatener_Contours(Contour s1, Contour s2)
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
Tableau_Point Contour_vers_tableau(Contour s)
{
	Tableau_Point t; 

	/* taille de t = taille de s */
	t.taille = s.taille;

	/* allocation dynamique du tableau de Point */
	t.tab = malloc(sizeof(Point) * t.taille);
	if (t.tab == NULL)
	{
		/* allocation impossible : arret du programe avec un message */
		fprintf(stderr, "Contour_vers_tableau : allocation impossible\n");
		exit(-1);
	}

	/* remplir le tableau de points t en parcourant la liste s */
	int k = 0; /* indice de l'élément dans t.tab */
	CelluleContour *cel = s.tete; /* pointeur sur l'élément dans s */
	while (cel)
	{
		t.tab[k] = cel->data;
		k++;
		cel = cel->suivant; /* passer a l'élément suivant dans la liste chainée */
	}

	return t;
}

