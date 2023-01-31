#include "contour.h"
#include "image.h"
#include "stdlib.h"
#include "stdio.h"

typedef struct Coord_Pixel {
	int x;
	int y;
} Coord_Pixel;

int main(int argc, char **argv)
{
	if (argc < 2) {
		printf("usage: ./%s <fichier_pbm>\n", argv[0]);
		exit(1);
	}

	Image I = lire_fichier_image(argv[1]);

	Coord_Pixel pixel_depart;
	if (trouve_pixel_depart(I, &pixel_depart.x, &pixel_depart.y)) {
		int x_initial = pixel_depart.x - 1;
		int y_initial = pixel_depart.y - 1;
		printf("Position du robot:\n");
		affiche_contour_a_la_volee(I, x_initial, y_initial);
	} else {
		printf("Aucun contour trouvé\n");
	}
}
