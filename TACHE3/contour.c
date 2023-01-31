#include "contour.h"
#include "robot.h"

bool trouve_pixel_depart(Image I, int *x_out, int *y_out)
{
	for (UINT y = 1; y < hauteur_image(I); y++) {
		for (UINT x = 1; x < largeur_image(I); x++) {
			/*
			 * On arrête dès qu'on trouve un pixel noir
			 * avec un pixel blanc au dessus
			 */
			if (get_pixel_image(I, x, y) == NOIR &&
			    get_pixel_image(I, x, y - 1) == BLANC) {
				*x_out = x;
				*y_out = y;
				return true;
			}
		}
	}
	return false;
}

void affiche_contour_a_la_volee(Image I, int x_initial, int y_initial)
{
	Robot r = creer_robot(x_initial, y_initial);

	/*
	 * La boucle s'exécute tant que le robot n'est pas revenu
	 * à sa position initiale.
	 */
	do {
		printf("(%d,%d)\n", r.x, r.y);
		avancer_robot(&r);
		orienter_robot(&r, I);
	} while (r.x != x_initial || r.y != y_initial || r.o != EST);

	printf("(%d,%d)\n", r.x, r.y);
}
