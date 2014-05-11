#include "Bullet.h"

Point<float> Bullet::next() {
    float x, y;

    life--;

    x = sin(angle) * speed + pos.getx();
    y = cos(angle) * speed + pos.gety();

    Point<float> nextPos(x, y);
    pos = nextPos;
    return nextPos;
}