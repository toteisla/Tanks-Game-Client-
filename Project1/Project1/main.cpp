#include <enet/enet.h>

#include "Game.h"
#include "Point.h"

int main() {

    Point<int> pt(2, 5);
    int x = pt.getx();
    int y = pt.gety();
    cout << x << ", " << y << endl;

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