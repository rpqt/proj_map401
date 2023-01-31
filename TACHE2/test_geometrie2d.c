#include "geometrie2d.h"
#include <math.h>
#include <assert.h>
#include <stdio.h>

const double eps = 0.00001;

void test_set_point()
{
    printf("TEST set_point: ");
    double x = -3.14;
    double y = 5.8793;
    Point P = set_point(x, y);
    assert(fabs(P.x - x) < eps);
    assert(fabs(P.y - y) < eps);
    printf("OK\n");
}

void test_set_vecteur()
{
    printf("TEST set_vecteur: ");
    double x = -3.14;
    double y = 5.8793;
    Vecteur V = set_vecteur(x, y);
    assert(fabs(V.x - x) < eps);
    assert(fabs(V.y - y) < eps);
    printf("OK\n");
}

void test_add_point()
{
    printf("TEST add_point: ");
    double x = -3.14;
    double y = 5.8793;
    double a = 2.42;
    double b = 3.125;
    Point P = set_point(x, y);
    Point P2 = set_point(a, b);
    Point P3 = add_point(P, P2);
    assert(fabs(P3.x - (P.x + P2.x)) < eps);
    assert(fabs(P3.y - (P.y + P2.y)) < eps);
    printf("OK\n");
}

void test_vect_bipoint()
{
    printf("TEST vect_bipoint: ");
    double x = -3.14;
    double y = 5.8793;
    double a = 2.42;
    double b = 3.125;
    Point P = set_point(x, y);
    Point P2 = set_point(a, b);
    Vecteur V = vect_bipoint(P, P2);
    double vx = a-x;
    double vy = b-y;
    assert(fabs(V.x - vx) < eps);
    assert(fabs(V.y - vy) < eps);
    printf("OK\n");
}

void test_add_vecteur()
{
    printf("TEST add_vecteur: ");
    double x = -3.14;
    double y = 5.8793;
    double a = 2.42;
    double b = 3.125;
    Vecteur V = set_vecteur(x, y);
    Vecteur V2 = set_vecteur(a, b);
    Vecteur V3 = add_vecteur(V, V2);
    assert(fabs(V3.x - (V.x + V2.x)) < eps);
    assert(fabs(V3.y - (V.y + V2.y)) < eps);
    printf("OK\n");
}

void test_produit_vecteur()
{
    printf("TEST produit_vecteur: ");
    double x = -3.14;
    double y = 5.8793;
    double facteur = 98.98371;
    Vecteur v = set_vecteur(x, y);
    Vecteur v2 = produit_vecteur(facteur, v);
    assert(fabs(v2.x - x * facteur) < eps);
    assert(fabs(v2.y - y * facteur) < eps);
    printf("OK\n");
}

void test_produit_point()
{
    printf("TEST produit_point: ");
    double x = -3.14;
    double y = 5.8793;
    double facteur = 98.98371;
    Point p = set_point(x, y);
    Point p2 = produit_point(facteur, p);
    assert(fabs(p2.x - x * facteur) < eps);
    assert(fabs(p2.y - y * facteur) < eps);
    printf("OK\n");
}

void test_produit_scalaire()
{
    printf("TEST produit_scalaire: ");
    double x = -3.14;
    double y = 5.8793;
    double a = 2.42;
    double b = 3.125;
    Vecteur V = set_vecteur(x, y);
    Vecteur V2 = set_vecteur(a, b);
    double scal = produit_scalaire(V, V2);
    assert(fabs(scal - (x*a + y*b)) < eps);
    printf("OK\n");
}

void test_norme_vecteur()
{
    printf("TEST norme_vecteur: ");
    double x = -3.14;
    double y = 5.8793;
    Vecteur V = set_vecteur(x, y);
    double norm = norme_vecteur(V);
    assert(fabs(norm - sqrt(x*x + y*y)) < eps);
    printf("OK\n");
}

void test_distance_points()
{
    printf("TEST distance_points: ");
    double x = -3.14;
    double y = 5.8793;
    double a = 2.42;
    double b = 3.125;
    Point P = set_point(x, y);
    Point P2 = set_point(a, b);
    Vecteur V = vect_bipoint(P, P2); 
    double res = norme_vecteur(V);
    double dist = distance_points(P, P2);
    assert(fabs(dist - res) < eps);
    printf("OK\n");
}


int main(int argc, char **argv)
{
    test_set_point();
    test_set_vecteur();
    test_add_point();
    test_vect_bipoint();
    test_add_vecteur();
    test_produit_vecteur();
    test_produit_point();
    test_produit_scalaire();
    test_norme_vecteur();
    test_distance_points();

}