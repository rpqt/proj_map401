#include "robot.h" 

void avancer_robot(Robot *r){
    switch (r->o)
    {
    case (NORD):
        r->y -= 1; 
        break;

    case (EST):
        r->x += 1; 
        break;
    
    case (SUD):
        r->y += 1; 
        break;
    
    case (OUEST):
        r->x -= 1; 
        break;
    
    default:
        break;
    }
}

void orienter_robot(Robot *r, Image I){
    Pixel pG;
    Pixel pD;

    switch (r->o)
    {
    case (NORD):
        pG = get_pixel_image(I, r->x, r->y);
        pD = get_pixel_image(I, r->x+1, r->y);
        break;

    case (EST):
        pG = get_pixel_image(I, r->x+1, r->y);
        pD = get_pixel_image(I, r->x+1, r->y+1);
        break;
    
    case (SUD):
        pG = get_pixel_image(I, r->x+1, r->y+1);
        pD = get_pixel_image(I, r->x, r->y+1);
        break;

    case (OUEST):
        pG = get_pixel_image(I, r->x, r->y+1);
        pD = get_pixel_image(I, r->x, r->y);
        break;

    default:
        break;
    }

    if (pG == NOIR){
        r->o = (r->o - 1) %4; /* tourner_a_gauche */
    }else if (pD == BLANC){
        r->o = (r->o + 1) %4; /* tourner_a_droite */
    }
}
