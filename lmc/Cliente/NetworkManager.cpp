#include "NetworkManager.h"

NetworkManager::NetworkManager() {

}

bool NetworkManager::init(const char *ip) {
    if (enet_initialize() != 0) {  //initialize enet
        cout << "An error occured while initializing ENet." << endl;
        return false;
    }

    atexit(enet_deinitialize);

    //create host
    address.host = ENET_HOST_ANY;
    address.port = PORT;

    client = enet_host_create(NULL, 1, 2, 57600/8, 14400/8);

    if (client == NULL) {
        cout << "An error occured while trying to create an ENet server host" << endl;
        return false;
    }

    enet_address_set_host(&address, ip);
    address.port = PORT;

    //create connection
    peer = enet_host_connect(client, &address, 2, 0);

    if (peer == NULL) {
        cout << "No available peers for initializing an ENet connection" << endl;
        return false;
    }



    return true;
}

bool NetworkManager::connect() {

    eventStatus = 1;

    while (1) {
        eventStatus = enet_host_service(client, &event, 50000);

        // If we had some event that interested us
        if (eventStatus > 0) {
            switch(event.type) {
            case ENET_EVENT_TYPE_CONNECT:
                cout << "(Client) We got a new connection from " << event.peer->address.host << endl;
                break;
            case ENET_EVENT_TYPE_RECEIVE:
                cout << "(Client) Message from server : " << event.packet->data << endl;
                // Lets broadcast this message to all
                // enet_host_broadcast(client, 0, event.packet);
                enet_packet_destroy(event.packet);
                break;

            case ENET_EVENT_TYPE_DISCONNECT:
                cout << "(Client) " << event.peer->data << " disconnected." << endl;
                // Reset client's information
                event.peer->data = NULL;
                break;
            }
        }

        cout << "Say > ";
        gets_s(message);

        if (strlen(message) > 0) {
            ENetPacket *packet = enet_packet_create(message, strlen(message) + 1, ENET_PACKET_FLAG_RELIABLE);
            enet_peer_send(peer, 0, packet);
        }
    }
    return false;
}