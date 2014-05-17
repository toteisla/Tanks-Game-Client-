#ifndef _MAP_H_
#define _MAP_H_

#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_image.h>

#include "rapidxml.hpp"
#include "rapidxml_utils.hpp"

#include "Player.h"
#include "BulletCollector.h"
#include "utils.h"
#include "Point.h"

using namespace rapidxml;
using namespace std;

#define MAPS_PATH "Maps/"

class Map {
private:
    char* mapName;
    string tileset;
    int tileHeight;
    int tileWidth; 

public :
    Map(char* mapName_) { mapName = mapName_; }
    void loadMap();
};

#endif