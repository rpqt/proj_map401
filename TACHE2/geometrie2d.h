#ifndef GEOMETRIE2D_H
#define GEOMETRIE2D_H

typedef struct Point_
{
    double x, y; /* Coordonnées */
} Point;


typedef struct Vecteur_
{
    double x, y; /* Coordonnées */
} Vecteur;

/* créé le point de coordonnées (x,y) */
Point set_point(double x, double y);

/* créé le vecteur de coordonnées (x,y) */
Vecteur set_vecteur(double x, double y);

/* somme P1+P2 */
Point add_point(Point P1, Point P2);

/* soustraction de P1-P2 */
Point sub_point(Point P1, Point P2);

/* vecteur correspondant au bipoint AB */
Vecteur vect_bipoint(Point A, Point B);

/* somme V1+V2 */
Vecteur add_vecteur(Vecteur V1, Vecteur V2);

/* produit du réel a par le vecteur V*/
Vecteur produit_vecteur(double a, Vecteur V);

/* produit du réel a par le Point P*/
Point produit_point(double a, Point P);

/* produit scalaire entre V1 et V2 */
double produit_scalaire(Vecteur V1, Vecteur V2);

/* norme euclidienne du vecteur V */
double norme_vecteur(Vecteur V);

/* distance entre P1 et P2 */
double distance_points(Point P1, Point P2);

/* distance entre un point P et le segment [A, B] */
double distance_point_segment(Point P, Point A, Point B);

#endif