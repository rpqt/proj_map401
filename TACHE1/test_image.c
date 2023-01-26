#include <stdlib.h>
#include "image.h"

void test_ecrire_image()
{
	printf("\n");
	printf("TEST ecrire_image\n");
	printf("=================\n");

	Image I = lire_fichier_image("caractere2.pbm");
	printf("Image du caractère 2:\n");
	ecrire_image(I);
	
	supprimer_image(&I);
}

void test_set_pixel_image()
{
	printf("\n");
	printf("TEST set_pixel_image\n");
	printf("=================\n");

	Image I = creer_image(5, 5);
	printf("Image vide 5x5:\n");
	ecrire_image(I);

	set_pixel_image(I, 2, 2, NOIR);
	set_pixel_image(I, 4, 2, NOIR);
	set_pixel_image(I, 2, 4, NOIR);
	set_pixel_image(I, 3, 4, NOIR);
	set_pixel_image(I, 4, 4, NOIR);

	printf("Image visage 5x5:\n");
	ecrire_image(I);

	supprimer_image(&I);
}

void test_negatif_image()
{
	printf("\n");
	printf("TEST negatif_image\n");
	printf("==================\n");

	Image I = lire_fichier_image("caractere2.pbm");
	printf("Image du caractère 2:\n");
	ecrire_image(I);

	Image I_neg = negatif_image(I);
	printf("Négatif du caractère 2:\n");
	ecrire_image(I_neg);

	supprimer_image(&I);
	supprimer_image(&I_neg);
}

int main(int argc, char **argv)
{
	test_ecrire_image();
	test_set_pixel_image();
	test_negatif_image();
	exit(0);
}
