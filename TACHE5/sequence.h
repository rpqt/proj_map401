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

CelluleContour *creer_CelluleContour(Point p);
Contour creer_Contour();
Contour ajouter_point(Contour *s, Point p);
Contour supprimer_Contour(Contour s);
Contour concatener_Contours(Contour s1, Contour s2);
Tableau_Point Contour_vers_tableau(Contour s);

#endif
