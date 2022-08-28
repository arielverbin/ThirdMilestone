
#include "ClientHandler.h"
ClientHandler::ClientHandler(void *server, int clientSock): server((Server*)server), clientSocket(clientSock) {}

void ClientHandler::serveWith(CLI& cli) const {
    cli.start();
    this->disconnect();
}

void ClientHandler::disconnect() const {
    close(clientSocket);
    server->clientDisconnected();
    std::cout << "Client (" << clientSocket << ") Disconnected. "
                            "(Active Clients: " << server->getClientsStatus() << ")" << std::endl;
}

int ClientHandler::getClientSock() const {return clientSocket;}
