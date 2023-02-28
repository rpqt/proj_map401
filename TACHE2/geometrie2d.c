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

/* soustraction de P1-P2 */
Point sub_point(Point P1, Point P2){
    return set_point(P1.x - P2.x, P1.y - P2.y);
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

/* distance entre un point P et le segment [A, B] */
double distance_point_segment(Point P, Point A, Point B){
    if (A.x == B.x && A.y == B.y){
        return distance_points(P, A);
    }

    Vecteur AP = vect_bipoint(A, P);
    Vecteur AB = vect_bipoint(A, B);
    Vecteur BP = vect_bipoint(B, P);

    double lambda = produit_scalaire(AP, AB)/produit_scalaire(AB, AB);

    // D = lambda(B - A)
    Point C = sub_point(B, A);
    Point D = produit_point(lambda, C);

    Point Q = add_point(A, D);
    Vecteur QP = vect_bipoint(Q, P);

    if (lambda < 0) {
        return norme_vecteur(AP);
    } else if (lambda > 1){
        return norme_vecteur(BP);
    } /* 0 <= lambda <= 1 */
    else return norme_vecteur(QP);
}