#include "Server.h"
#include <iostream>
int main(){
    std::cout << "---------------------Server---------------------" << std::endl;
    Server server(5555, 4);
    server.acceptClients();
}

