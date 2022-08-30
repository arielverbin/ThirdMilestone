
#include "Client.h"

Client::Client() : connected(false), socket(-1){}

bool Client::connectTo(int serverPort) {
    if (connected) {
        std::cout << "Already connected to a server." << std::endl;
        return false;
    }
    const char *ip_address = "127.0.0.1"; //connection between the device to itself;
    this->socket = ::socket(AF_INET, SOCK_STREAM, 0);

    if (socket < 0) { perror("Error creating socket.");
        return false;
    }
    struct sockaddr_in sin{};
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = inet_addr(ip_address);
    sin.sin_port = htons(serverPort);

    if (connect(socket, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("Error connecting to server."); return false;
    }
    this->connected = true;
    return true;
}

void Client::getService() const {
    SocketIO socketIo(socket);
    CommandHandler commandHandler(socketIo);
    commandHandler.handle();
}

void Client::disconnect() {
    close(socket);
    this->socket = -1;
    this->connected = false;
}