#include <iostream>
#include "Client.h"
int main(int argc, char **argv){
    int server = std::stoi(argv[1]);
    std::cout << "---------------------Client---------------------" << std::endl;
    Client client;
    if(client.connectTo(server))
        std::cout << "# Connected to Server!\n"<< std::endl;
    client.getService();
    std::cout << "# Disconnecting..." << std::endl;
    client.disconnect();
    return 0;
}
