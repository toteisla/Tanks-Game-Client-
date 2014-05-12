#include "game.h"

void Game::guardar_config(){
    cout << "Guardando configuracion" << endl;
    ofstream file;
    file.open("config.txt");
    if (file.is_open()) {
        file << "res_w " << resX << endl;
        file << "res_h " << resY << endl;
        if (ventana_completa) 
            file << "completa 1" << endl;
        else 
            file << "completa 0" <<  endl;
        file.close();
    } else
        cout << "No encuentro config.txt" << endl;
}

int Game::ini(){

    bool done = false;
    bool redraw = true;

    int counter = 0;

    Point<float> cam_pos(50, 50);
    Point<float> mousePos(0, 0);

    bool keys[8] = {false, false, false, false,false,false,false,false};
    bool raton_mov[4] = {false,false,false,false};


    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_EVENT_QUEUE *event_queue = NULL;
    ALLEGRO_TIMER *timer = NULL;
    ALLEGRO_MOUSE_STATE estado_raton;

    if(!al_init())										//initialize Allegro
        return -1;

    if (ventana_completa)	
        al_set_new_display_flags(ALLEGRO_FULLSCREEN);
    else
        al_set_new_display_flags(0);
    display = al_create_display(resX, resY);			//create our display object

    if(!display)										//test display object
        return -1;

    Utils utils;
    Point<float> playerPos(al_get_display_width(display) / 2 , al_get_display_height(display));
    Player player(playerPos, 20);

    if(!al_init_primitives_addon()){
        fprintf(stderr, "failed to initialize primitives addon!\n");
        return -1;
    }

    al_init_image_addon();
    al_init_primitives_addon();
    al_install_keyboard();
    al_install_mouse();

    event_queue = al_create_event_queue();
    timer = al_create_timer(1.0 / fps);

    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_mouse_event_source());

    al_start_timer(timer);

    while(!done)
    {
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);

        player.drawPlayer(mousePos);//Draw the player

        if(ev.type == ALLEGRO_EVENT_KEY_DOWN)
        {
            switch(ev.keyboard.keycode)
            {
            case ALLEGRO_KEY_W:
                keys[W] = true;
                break;
            case ALLEGRO_KEY_S:
                keys[S] = true;
                break;
            case ALLEGRO_KEY_D:
                keys[D] = true;
                break;
            case ALLEGRO_KEY_A:
                keys[A] = true;
                break;
            case ALLEGRO_KEY_UP:
                keys[UP] = true;
                break;
            case ALLEGRO_KEY_DOWN:
                keys[DOWN] = true;
                break;
            case ALLEGRO_KEY_RIGHT:
                keys[RIGHT] = true;
                break;
            case ALLEGRO_KEY_LEFT:
                keys[LEFT] = true;
                break;					
            }


        }
        else if(ev.type == ALLEGRO_EVENT_KEY_UP)
        {
            switch(ev.keyboard.keycode)
            {
            case ALLEGRO_KEY_W:
                keys[W] = false;
                break;
            case ALLEGRO_KEY_S:
                keys[S] = false;
                break;
            case ALLEGRO_KEY_D:
                keys[D] = false;
                break;
            case ALLEGRO_KEY_A:
                keys[A] = false;
                break;
            case ALLEGRO_KEY_ESCAPE:
                done = true;
                break;
            case ALLEGRO_KEY_UP:
                keys[UP] = false;
                break;
            case ALLEGRO_KEY_DOWN:
                keys[DOWN] = false;
                break;
            case ALLEGRO_KEY_RIGHT:
                keys[RIGHT] = false;
                break;
            case ALLEGRO_KEY_LEFT:
                keys[LEFT] = false;
                break;	
            }
        }
        else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        {
            done = true;
        }
        else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
            al_get_mouse_state(&estado_raton);
            if (estado_raton.buttons & 1) {
                cout << "Pew Pew" << endl;
                bulletCollector.push(player.getPos(), 1.0, utils.getAlpha(player.getPos(), mousePos));
            }
        }
        else if (ev.type == ALLEGRO_EVENT_MOUSE_AXES) {
            al_get_mouse_state(&estado_raton);
            mousePos.setx(estado_raton.x);
            mousePos.sety(estado_raton.y);
            if (mousePos.gety() <= 50) raton_mov[UP] = true; else if (mousePos.gety() > 50) raton_mov[UP] = false;
            if (mousePos.gety() >= resY-50)  raton_mov[DOWN] = true; else if (mousePos.gety() < resY-50) raton_mov[DOWN] = false;
            if (mousePos.getx() <= 50) raton_mov[LEFT] = true; else if (mousePos.getx() > 50) raton_mov[LEFT] = false;
            if (mousePos.getx() >= resX-50) raton_mov[RIGHT] = true; else if (mousePos.getx() < resX-50) raton_mov[RIGHT] = false;
        }
        else if(ev.type == ALLEGRO_EVENT_TIMER)
        {
            if (keys[W] || keys[UP] || raton_mov[UP]) { if (cam_pos.getx() > 0 && cam_pos.gety() > 0){ player.moveY(-1);}}
            if (keys[S] || keys[DOWN] || raton_mov[DOWN]) { if (cam_pos.getx() < 99 && cam_pos.gety() < 99){ player.moveY(1);}}
            if (keys[A] || keys[LEFT] || raton_mov[LEFT]) { if (cam_pos.getx() < 99 && cam_pos.gety() > 0){ player.moveX(-1);}}
            if (keys[D] || keys[RIGHT] || raton_mov[RIGHT]) { if (cam_pos.getx() > 0 && cam_pos.gety() < 99){ player.moveX(1);}}

            redraw = true;
        }

        if(redraw && al_is_event_queue_empty(event_queue)) {
            redraw = false;

            bulletCollector.next();

            al_flip_display();
            al_clear_to_color(al_map_rgb(0,0,0));
        }
    }
    al_destroy_event_queue(event_queue);
    al_destroy_timer(timer);
    al_destroy_display(display);						//destroy our display object

    return 0;
}
