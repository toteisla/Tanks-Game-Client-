#include <enet/enet.h>

#include "Game.h"

int main() {

    Game game(800, 600, false, 60);
    game.ini();

    /*
    if (enet_initialize () != 0) {
        fprintf (stderr, "An error occurred while initializing ENet.\n");
        return EXIT_FAILURE;
    }
    atexit (enet_deinitialize);
    */

    return 0;
}