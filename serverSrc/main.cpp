#include "Server.h"
#include <iostream>
int main(int argc, char **argv){
    std::cout << "----------------------Server----------------------" << std::endl;
    Server server(std::stoi(argv[1]), std::stoi(argv[2]));
    server.acceptClients();
}

