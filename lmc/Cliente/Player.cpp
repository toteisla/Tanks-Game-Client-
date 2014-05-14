#include "Player.h"
#include "utils.h"

void Player::drawPlayer(Point<float> mousePos){
    int barrelSize = size;
    float x, y;
    float angle;

    Utils utils;

    al_draw_filled_rectangle(pos.getx() - size / 2, pos.gety() - size / 2, pos.getx() + size / 2, pos.gety() + size / 2, al_map_rgb(255, 0, 0));

    angle = utils.getAlpha(pos, mousePos);

    x = cos(angle) * barrelSize + pos.getx();
    y = sin(angle) * barrelSize + pos.gety();

    al_draw_line(pos.getx(), pos.gety(), x, y, al_map_rgb(0, 255, 0), 2);
}

void Player::shoot(Point<float> mousePos){
    /* int pos_bullet_x = pos_x;
    int pos_bullet_y = pos_y;

    ALLEGRO_TIMER *timer;
    timer = al_create_timer(0.2);
    al_start_timer(timer);

    while(pos_bullet_x != mouse_x && pos_bullet_y != mouse_y){
    if(mouse_x <= pos_x){ pos_bullet_x--; }
    if(mouse_x > pos_x){ pos_bullet_x++; }
    if(mouse_y <= pos_y){ pos_bullet_y--; }
    if(mouse_y > pos_y){ pos_bullet_y++; }

    al_draw_filled_rectangle(pos_bullet_x - 2, pos_bullet_y - 2, pos_bullet_x + 2, pos_bullet_y + 2, al_map_rgb(75, 125, 255));
    }
    al_destroy_timer(timer);*/
}