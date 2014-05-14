#include "NetworkManager.h"

NetworkManager::NetworkManager() {
    eventStatus = 0; 
}

bool NetworkManager::init() {
    if (enet_initialize() != 0) {  //initialize enet
        cout << "An error occured while initializing ENet." << endl;
        return false;
    }

    atexit(enet_deinitialize);

    //create server
    address.host = ENET_HOST_ANY;
    address.port = PORT;

    server = enet_host_create(&address, 32, 2, 0, 0);

    if (server == NULL) {
        cout << "An error occured while trying to create an ENet server host" << endl;
        return false;
    }

    return true;
}

bool NetworkManager::listen() {
    eventStatus = 1;

    while (1) {
        eventStatus = enet_host_service(server, &event, 50000);

        // If we had some event that interested us
        if (eventStatus > 0) {
            switch(event.type) {
            case ENET_EVENT_TYPE_CONNECT:
                cout << "(Server) We got a new connection from " << event.peer->address.host << endl;
                break;

            case ENET_EVENT_TYPE_RECEIVE:
                cout << "(Server) Message from client : " << event.packet->data << endl;
                // Lets broadcast this message to all
                enet_host_broadcast(server, 0, event.packet);
                break;

            case ENET_EVENT_TYPE_DISCONNECT:
                cout << event.peer->data << " disconnected." << endl;
                // Reset client's information
                event.peer->data = NULL;
                break;

            }
        }
    }

    return false;
}