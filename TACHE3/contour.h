#ifndef CONTOUR_H
#define CONTOUR_H

#include "../TACHE1/image.h"
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

/*
 * Cherche un pixel de départ pour un contour dans l'image donnée.
 * Si un pixel satisfait les conditions, retourne true et écrit ses coordonnées
 * dans [x_out] et [y_out].
 * Sinon retourne false.
 */
bool trouve_pixel_depart(Image I, int *x_out, int *y_out);

/*
 * Affiche le contour partant du [point_initial] donné dans l'image [I]
 * sur la sortie standard.
 */
void affiche_contour_a_la_volee(Image I, int x_initial, int y_initial);

/* créer une cellule de liste avec l'élément p 
   renvoie le pointeur sur la cellule créée 
   la fonction s'arrete si la création n'a pas pu se faire */
Cellule *creer_cellule(Point p);

/* créer une liste vide */
Sequence creer_sequence();

/* ajouter le point p en fin de la liste s, renvoie la liste s modifiée */
Sequence ajouter_point(Sequence s, Point p);

/* suppression de tous les éléments de la liste, renvoie la liste s vide */
Sequence supprimer_sequence(Sequence s);

/* concatène s2 à la suite de s1, renvoie la liste s1 modifiée */
Sequence concatener_sequences(Sequence s1, Sequence s2);

/* créer une séquence de points sous forme d'un tableau de points
   à partir de la liste de points s */
Tableau_Point sequence_vers_tableau(Sequence s);

/* affiche le contour s à l'écran
   cette fonction montre un exemple de conversion d'une liste de points en
   tableau de points afin de pouvoir par la suite accéder aux éléments d'une
   séquence de points par indice */
void affiche_contour(Sequence s);

/* retourne un contour sous forme de liste chainée 
   prend une image et les coordonées de départ du robot */
Sequence image_vers_contour(Image I, int x_initial, int y_initial);

/* écrit le nombre de points du contour suivi par la liste de points */
void ecrire_contour(FILE *f, Sequence s);

/* écrit plusieurs contours précédés du nombre de contours */
void ecrire_fichier_contour(FILE *f, Sequence s);

#endif