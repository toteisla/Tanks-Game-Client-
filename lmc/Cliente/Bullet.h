#ifndef _BULLET_H_
#define _BULLET_H_

#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include "Point.h"
#include <math.h>

class Bullet {
private:
    Point<float> pos;
    float speed;
    float angle;
    int life;
    void drawBullet(Point<float> pos, float rad);
public :
    Bullet() { speed = 0.0; angle = 0.0; life = 500;}
    Bullet(Point<float> pos_, float speed_, float angle_) {
        pos = pos_; 
        speed = speed_; 
        angle = angle_; 
        life = 500;
    }

    Point<float> getPos() { return pos; }
    void setPos(Point<float> val) { pos = val;}
    float getSpeed() { return speed; }
    void setSpeed(const float val) { speed = val; }
    float getAngle() { return angle; }
    void setAngle(const float val) { angle = val;}
    int getLife() { return life; }
    void setLife(const int val) { life = val; }
    Point<float> next(); 
};

#endif