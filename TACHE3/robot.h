#include "../TACHE1/image.h"
/* 
 Type enuméré Orientation équivalent au char avec NORD=0,EST=1,SUD=2,OUEST=3
 */
typedef enum {NORD=0,EST=1,SUD=2,OUEST=3} Orientation;

typedef struct Robot {
    int x, y; /* Position */
    Orientation o;
} Robot;

Robot creer_robot(int x, int y);

void avancer_robot(Robot *r);

void orienter_robot(Robot *r, Image I);
