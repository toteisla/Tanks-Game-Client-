#include "Bullet.h"

Point<float> Bullet::next() {
    float x, y;

    life--;

    x = cos(angle) * speed + pos.getx();
    y = sin(angle) * speed + pos.gety();

    Point<float> nextPos(x, y);
    pos = nextPos;
    drawBullet(pos, 2);
    return nextPos;
}

void Bullet::drawBullet(Point<float> pos, float rad){
    al_draw_filled_circle(pos.getx(), pos.gety(), rad, al_map_rgb(75, 125, 255));
}