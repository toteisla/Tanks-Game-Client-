#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include "Point.h"

class Player {
private:
    Point<float> pos;
    int size;
public :
    Player(Point<float> _pos , int _size) { pos = _pos ; size = _size;}
    void drawPlayer(Point<float> mousePos);// Pinta jugador, se le pasa la posicion del raton para pintar el cañon
    void shoot(Point<float> mousePos);

    void moveY(const int dir) {
        pos.sety(pos.gety() + dir);
    }
    void moveX(const int dir) { pos.setx(pos.getx() + dir); }
    Point<float> getPos() { return pos; }

    Point<float> getPos() { return pos; }

};

#endif