#include "Player.h"

void Player::drawPlayer(int mouse_x, int mouse_y){
    int barrelSize = size + size / 2;
    al_draw_filled_rectangle(pos_x - size / 2, pos_y - size / 2, pos_x + size / 2, pos_y + size / 2, al_map_rgb(255, 0, 0));

    al_draw_line(pos_x, pos_y, mouse_x, mouse_y, al_map_rgb(0, 0, 0), 2);
}

void Player::shoot(int mouse_x, int mouse_y){
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