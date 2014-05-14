#ifndef _NETWORKMANAGER_H_
#define _NETWORKMANAGER_H_

#include <enet/enet.h>
#include <iostream>
#include <string>

using namespace std;



class NetworkManager {
private:
    static const int PORT = 4321;
    static const int MAX_MSG_SIZE = 1024;

    ENetAddress address;
    ENetHost *client;
    ENetPeer *peer;
    char message[MAX_MSG_SIZE];
    ENetEvent event;
    int eventStatus;

public :
    NetworkManager();

    bool init(const char *ip);
    bool connect();

};

#endif

