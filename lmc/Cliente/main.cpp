#include <enet/enet.h>

#include "Game.h"
#include "Point.h"
#include "NetworkManager.h"

int main() {

    Game game(800, 600, false, 60);
    game.ini();

    NetworkManager netmanager;
    if (netmanager.init("localhost")) {
        netmanager.connect();
    }

    return 0;
}