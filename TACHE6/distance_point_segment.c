#include <stdio.h>
#include "../TACHE2/geometrie2d.h"

int main(int argc, char **argv)
{
	Point P, A, B;
	printf("Px? ");
	scanf("%lf", &P.x);
	printf("Py? ");
	scanf("%lf", &P.y);
	printf("Ax? ");
	scanf("%lf", &A.x);
	printf("Ay? ");
	scanf("%lf", &A.y);
	printf("Bx? ");
	scanf("%lf", &B.x);
	printf("By? ");
	scanf("%lf", &B.y);

	double distance = distance_point_segment(P, A, B);
	printf("P = (%lf, %lf)\n", P.x, P.y);
	printf("A = (%lf, %lf)\n", A.x, A.y);
	printf("B = (%lf, %lf)\n", B.x, B.y);
	printf("S = [A, B]\n");
	printf("Distance point-segment d(A, S) = %lf\n", distance);

	return 0;
}
