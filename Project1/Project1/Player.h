#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>

class Player {
private:
    int pos_x, pos_y, size;
public :
    Player(int x1,int y1, int _size) { pos_x  = x1; pos_y = y1 ; size = _size;}
    void drawPlayer(int mouse_x, int mouse_y);
    void shoot(int mouse_x, int mouse_y);

    void moveY(const int dir) {pos_y = pos_y + dir;}
    void moveX(const int dir) {pos_x = pos_x + dir;}

};

#endif