#ifndef _BULLETCOLLECTOR_H_
#define _BULLETCOLLECTOR_H_

#include <allegro5\allegro.h>

#include "Point.h"
#include "Bullet.h"

using namespace::std;

const int MAX_COLLECTOR_SIZE = 1024;

class BulletCollector {
private:
    Bullet container[MAX_COLLECTOR_SIZE];
    int index;
public :
    BulletCollector() { index = 0; }
    int push(Point<float> pos, const float speed, const float angle);
    int push(const float x, const float y, const float speed, const float angle);
    void erase(const int idx);

    void next();
};

#endif
