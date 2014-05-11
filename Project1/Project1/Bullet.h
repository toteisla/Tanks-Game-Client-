#ifndef _BULLETCOLLECTOR_H_
#define _BULLETCOLLECTOR_H_

#include <allegro5\allegro.h>

class Bullet {
private:
    int x;      //actual position x axe 
    int y;      //actual position y axe
    int speed;
    float angle;
public :
    Bullet(int x_, int y_, int speed_, float angle_) { x = x_; y = y_; speed = speed_; angle = angle_; }
    
};

#endif