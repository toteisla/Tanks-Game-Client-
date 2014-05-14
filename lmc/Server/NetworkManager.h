#ifndef _NETWORKMANAGER_H_
#define _NETWORKMANAGER_H_

#include <enet/enet.h>
#include <iostream>
#include <string>

using namespace std;

class NetworkManager {
private:
    static const int PORT = 4321;

    ENetAddress address;
    ENetHost *server;
    ENetEvent event;
    int eventStatus;

public :
    NetworkManager();

    bool init();
    bool listen();
};

#endif