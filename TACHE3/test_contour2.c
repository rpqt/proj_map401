#include "contour.h"

int main()
{
    Contour C1, C2;

    /* initialiser C1 comme contour vide */
    C1 = creer_sequence();
    printf("C1 : "); affiche_contour(C1);

    /* ajouter les points (5,3),(3,1),(7,2) et (1,6) dans C1 */
    C1 = ajouter_point(&C1, set_point(5,3));
    C1 = ajouter_point(&C1, set_point(3,1));
    C1 = ajouter_point(&C1, set_point(7,2));
    C1 = ajouter_point(&C1, set_point(1,6));
    printf("C1 : "); affiche_contour(C1);

    /* ajouter le point (4,1) dans C1 */
    C1 = ajouter_point(&C1, set_point(4,1));
    printf("C1 : "); affiche_contour(C1);

    /* créer le contour C2 avec les points (9,5) et (5,7) */
    C2 = creer_sequence();
    C2 = ajouter_point(&C2, set_point(9,5));
    C2 = ajouter_point(&C2, set_point(5,7)); 
    printf("C2 : "); affiche_contour(C2);

    /* concaténer C2 à la suite de C1 */
    C1 = concatener_sequences(C1,C2);
    printf("C1 : "); affiche_contour(C1);

    /* supprimer le contour C1*/
    C1 = supprimer_sequence(C1);
    printf("C1 : "); affiche_contour(C1);
}
