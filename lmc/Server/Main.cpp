#include <enet/enet.h>
#include <stdio.h>
#include "NetworkManager.h"
 
int main(int argc, char **argv) {
    NetworkManager netmanager;

    if (netmanager.init()) {
        netmanager.listen();
    }
}