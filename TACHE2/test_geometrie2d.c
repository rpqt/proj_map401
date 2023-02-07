#include "geometrie2d.h"
#include <assert.h>
#include <math.h>
#include <stdio.h>

static const double eps = 0.00001;

static int i_test = 0;
static int nb_ok = 0;
static const int nb_tests = 12;

static void test(const char *nom)
{
	i_test++;
	printf("%2d/%2d %40s ", i_test, nb_tests, nom);
}

static void ok()
{
	nb_ok++;
	printf("ok\n");
}

static void fail()
{
	printf("fail");
}

void test_set_point()
{
	test("set point");
	double x = -3.14;
	double y = 5.8793;
	Point P = set_point(x, y);
	assert(fabs(P.x - x) < eps);
	assert(fabs(P.y - y) < eps);
	ok();
}

void test_set_vecteur()
{
	test("set_vecteur");
	double x = -3.14;
	double y = 5.8793;
	Vecteur V = set_vecteur(x, y);
	assert(fabs(V.x - x) < eps);
	assert(fabs(V.y - y) < eps);
	ok();
}

void test_add_point()
{
	test("add_point");
	double x = -3.14;
	double y = 5.8793;
	double a = 2.42;
	double b = 3.125;
	Point P = set_point(x, y);
	Point P2 = set_point(a, b);
	Point P3 = add_point(P, P2);
	assert(fabs(P3.x - (P.x + P2.x)) < eps);
	assert(fabs(P3.y - (P.y + P2.y)) < eps);
	ok();
}

void test_vect_bipoint()
{
	test("vect_bipoint");
	double x = -3.14;
	double y = 5.8793;
	double a = 2.42;
	double b = 3.125;
	Point P = set_point(x, y);
	Point P2 = set_point(a, b);
	Vecteur V = vect_bipoint(P, P2);
	double vx = a - x;
	double vy = b - y;
	assert(fabs(V.x - vx) < eps);
	assert(fabs(V.y - vy) < eps);
	ok();
}

void test_add_vecteur()
{
	test("add_vecteur");
	double x = -3.14;
	double y = 5.8793;
	double a = 2.42;
	double b = 3.125;
	Vecteur V = set_vecteur(x, y);
	Vecteur V2 = set_vecteur(a, b);
	Vecteur V3 = add_vecteur(V, V2);
	assert(fabs(V3.x - (V.x + V2.x)) < eps);
	assert(fabs(V3.y - (V.y + V2.y)) < eps);
	ok();
}

void test_produit_vecteur()
{
	test("produit_vecteur");
	double x = -3.14;
	double y = 5.8793;
	double facteur = 98.98371;
	Vecteur v = set_vecteur(x, y);
	Vecteur v2 = produit_vecteur(facteur, v);
	assert(fabs(v2.x - x * facteur) < eps);
	assert(fabs(v2.y - y * facteur) < eps);
	ok();
}

void test_produit_point()
{
	test("produit_point");
	double x = -3.14;
	double y = 5.8793;
	double facteur = 98.98371;
	Point p = set_point(x, y);
	Point p2 = produit_point(facteur, p);
	assert(fabs(p2.x - x * facteur) < eps);
	assert(fabs(p2.y - y * facteur) < eps);
	ok();
}

void test_produit_scalaire()
{
	test("produit_scalaire");
	double x = -3.14;
	double y = 5.8793;
	double a = 2.42;
	double b = 3.125;
	Vecteur V = set_vecteur(x, y);
	Vecteur V2 = set_vecteur(a, b);
	double scal = produit_scalaire(V, V2);
	assert(fabs(scal - (x * a + y * b)) < eps);
	ok();
}

void test_norme_vecteur()
{
	test("norme_vecteur");
	double x = -3.14;
	double y = 5.8793;
	Vecteur V = set_vecteur(x, y);
	double norm = norme_vecteur(V);
	assert(fabs(norm - sqrt(x * x + y * y)) < eps);
	ok();
}

void test_distance_points()
{
	test("distance_points");
	double x = -3.14;
	double y = 5.8793;
	double a = 2.42;
	double b = 3.125;
	Point P = set_point(x, y);
	Point P2 = set_point(a, b);
	Vecteur V = vect_bipoint(P, P2);
	double res = norme_vecteur(V);
	double dist = distance_points(P, P2);

	if (fabs(dist - res) < eps) {
		ok();
	} else {
		fail();
	}
}

void test_produit_scalaire_orthonaux()
{
	test("produit_scalaire_orthogonaux");
	Vecteur u = set_vecteur(1, 2);
	Vecteur v = set_vecteur(-9, 4.5);
	double p = produit_scalaire(u, v);

	if (p < eps) {
		ok();
	} else {
		fail();
	};
}

void test_produit_scalaire_un_zero()
{
	test("produit_scalaire_un_zero");
	Vecteur u  = set_vecteur(4, 9);
	Vecteur v = set_vecteur(0, 5);
	double p = produit_scalaire(u, v);

	if (fabs(p - 5*9) < eps) {
		ok();
	} else {
		fail();
	};
}

void test_produit_scalaire_deux_zeros()
{
	test("produit_scalaire_un_zero");
	Vecteur u  = set_vecteur(4, 9);
	Vecteur v = set_vecteur(0, 5);
	double p = produit_scalaire(u, v);

	if (fabs(p - 5*9) < eps) {
		ok();
	} else {
		fail();
	};
}

int main(int argc, char **argv)
{
	printf("\n");
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
	test_produit_scalaire_orthonaux();
	test_produit_scalaire_un_zero();
	test_produit_scalaire_deux_zeros();
	printf("\nRésultat: %d/%d tests réussis.\n", nb_ok, i_test);
}
