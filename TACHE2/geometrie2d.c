#include "geometrie2d.h"
#include <math.h>

/* créé le point de coordonnées (x,y) */
Point set_point(double x, double y){
    Point P = {x, y};
    return P;
}

/* créé le vecteur de coordonnées (x,y) */
Vecteur set_vecteur(double x, double y){
    Vecteur V = {x, y};
    return V;
}

/* somme P1+P2 */
Point add_point(Point P1, Point P2){
    return set_point(P1.x + P2.x, P1.y + P2.y);
}

/* vecteur correspondant au bipoint AB */
Vecteur vect_bipoint(Point A, Point B){
    Vecteur V = {B.x - A.x, B.y - A.y};
    return V;
}

/* somme V1+V2 */
Vecteur add_vecteur(Vecteur V1, Vecteur V2){
    return set_vecteur(V1.x + V2.x, V1.y + V2.y);
}

/* produit du réel a par le vecteur V*/
Vecteur produit_vecteur(double a, Vecteur V){
    return set_vecteur(V.x*a, V.y*a);
}

/* produit du réel a par le Point P*/
Point produit_point(double a, Point P){
    return set_point(P.x*a,P.y*a);
}

/* produit scalaire entre V1 et V2 */
double produit_scalaire(Vecteur V1, Vecteur V2){
    return V1.x*V2.x + V1.y*V2.y;
}

/* norme euclidienne du vecteur V */
double norme_vecteur(Vecteur V){
    return sqrt(V.x*V.x + V.y*V.y);
}

/* distance entre P1 et P2 */
double distance_points(Point P1, Point P2){
    Vecteur V = vect_bipoint(P1, P2);
    return norme_vecteur(V);
}
