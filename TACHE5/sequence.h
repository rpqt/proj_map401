#ifndef SEQUENCE_POINTS_H
#define SEQUENCE_POINTS_H

#include "../TACHE2/geometrie2d.h"

typedef struct Cellule
{   
    Point data; /* point du contour */
    struct Cellule *suivant; /* pointeur sur l'élément suivant */

} Cellule;


typedef struct Sequence
{
    int taille; /* nombre d'éléments dans la liste */
    Cellule *tete; /* pointeur sur le premier élément de la liste */
    Cellule *fin; /* pointeur sur le dernier élément de la liste */

} Sequence, Contour;

typedef struct Tableau_Point
{
    int taille; /* nombre d'éléments dans le tableau */
    Point *tab; /* pointeur vers le tableau des éléments */
} Tableau_Point;

Cellule *creer_cellule(Point p);
Sequence creer_sequence();
Sequence ajouter_point(Sequence *s, Point p);
Sequence supprimer_sequence(Sequence s);
Sequence concatener_sequences(Sequence s1, Sequence s2);
Tableau_Point sequence_vers_tableau(Sequence s);

#endif
