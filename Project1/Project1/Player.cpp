#include "Player.h"

void Player::drawPlayer(){
    al_draw_filled_rectangle(pos_x - size / 2, pos_y - size / 2, pos_x + size / 2, pos_y + size / 2, al_map_rgb(255, 0, 0));
}