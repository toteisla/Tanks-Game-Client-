#ifndef _GAME_H_
#define _GAME_H_

#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>

using namespace std;

//#include "map.h"
#include "Player.h"
#include "BulletCollector.h"
#include "utils.h"
#include "Point.h"

//const int MAX_ENTIDADES = 255;

class Game {
private:
    int resX, resY, fps;
    bool ventana_completa;
    enum KEYS{ UP, DOWN, LEFT, RIGHT, W, S, A,D};
    BulletCollector bulletCollector;
public :
    Game(int x,int y, bool _vc, int _fps) { resX  = x; resY = y; fps = _fps; ventana_completa = _vc; }
    int ini();
    int reset(int _resX, int _resY);
    void guardar_config();
};

#endif