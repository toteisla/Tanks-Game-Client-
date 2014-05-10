#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>

class Player {
    private:
        
    public :
        int pos_x, pos_y, size;
        Player(int x1,int y1, int _size) { pos_x  = x1; pos_y = y1 ; size = _size;}
        void drawPlayer();

};

#endif