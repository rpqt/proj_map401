#ifndef Contour_POINTS_H
#define Contour_POINTS_H

#include "../TACHE2/geometrie2d.h"

typedef struct CelluleContour
{   
    Point data; /* point du contour */
    struct CelluleContour *suivant; /* pointeur sur l'élément suivant */

} CelluleContour;

typedef struct Cellule
{
    Contour contour; /* contour de la séquence */
    struct Cellule *suivant; /* pointeur sur l'élément suivant */
} Cellule;

typedef struct Contour
{
    int taille; /* nombre d'éléments dans la liste */
    CelluleContour *tete; /* pointeur sur le premier élément de la liste */
    CelluleContour *fin; /* pointeur sur le dernier élément de la liste */

} Contour;

typedef struct Sequence
{
    int taille; /* nombre d'éléments dans liste */
    Cellule *tete; /* pointeur sur le premier élément de la liste */
    Cellule *fin; /* pointeur sur le dernier élément de la liste */
} Sequence 

typedef struct Tableau_Point
{
    int taille; /* nombre d'éléments dans le tableau */
    Point *tab; /* pointeur vers le tableau des éléments */
} Tableau_Point;

/* créer une CelluleContour de liste avec le point p 
   renvoie le pointeur sur la CelluleContour créée 
   la fonction s'arrete si la création n'a pas pu se faire */
CelluleContour *creer_CelluleContour(Point p);

/* créer une Cellule de liste avec le contour c
   renvoie le pointeur sur la CelluleContour créée 
   la fonction s'arrete si la création n'a pas pu se faire */
Cellule *creer_Cellule(Contour c);

/* créer un contour vide */
Contour creer_Contour();

/* créer une sequence vide */
Sequence creer_Sequence();

/* ajoute le point p en fin du contour c, renvoie le contour c modifiée */
Contour ajouter_point(Contour *s, Point p);

/* ajoute le contour c en fin de la sequence s, renvoie la sequence s modifiée */
Sequence ajouter_contour(Sequence *s, Contour c);

/* suppression de tous les éléments du contour, renvoie le contour c vide */
Contour supprimer_Contour(Contour s);

/* suppression de tous les éléments de la liste, renvoie la liste s vide */
Sequence supprimer_sequence(Sequence s);

/* concatène s2 à la suite de s1, renvoie la liste s1 modifiée */
Contour concatener_Contours(Contour s1, Contour s2);

/* créer une séquence de points sous forme d'un tableau de points
   à partir de la liste de points s */
Tableau_Point Contour_vers_tableau(Contour s);

#endif
