#include "sequence.h"
#include <stdlib.h>
#include <stdio.h>

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

