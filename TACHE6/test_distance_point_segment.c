#include "../TACHE2/geometrie2d.h"
#include <stdio.h>
#include <stdlib.h>


void test_distance(double Px, double Py, double Ax, double Ay, double Bx, double By, double d){

    Point P = set_point(Px, Py);
    Point A = set_point(Ax, Ay);
    Point B = set_point(Bx, By);
    
    double distance = distance_point_segment(P, A, B);

    if (distance == d){
        printf("La distance obtenue est égale a la distance attendue.\n");
    }else {
        printf("Erreur! La distance attendue était: %lf\n", d);
        printf("La distance obtenue est: %lf\n", distance);
    }
}

int main(int argc, char **argv){

    if (argc < 1) {
		printf("usage: %s <tests-distance.txt>\n", argv[0]);
		exit(1);
	}
    
    FILE *fp;
    double Px, Py, Ax, Ay, Bx, By, d;
    int nb_tests, i;

    fp = fopen("tests-distance.txt", "r");
    fscanf(fp, "%d", &nb_tests);

    for (i=0; i<nb_tests; i++){
        fscanf(fp, "%lf %lf %lf %lf %lf %lf %lf", &Px, &Py, &Ax, &Ay, &Bx, &By, &d);
        test_distance(Px, Py, Ax, Ay, Bx, By, d);
    }

    fclose(fp);
}



