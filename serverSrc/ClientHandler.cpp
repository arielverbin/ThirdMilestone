
#include "ClientHandler.h"
ClientHandler::ClientHandler(void *server, int clientSock):
        server((Server*)server), clientSocket(clientSock), clientData() {}

void ClientHandler::serveWith(CLI& cli) const {
    cli.start();
    this->disconnect();
}

void ClientHandler::disconnect() const {
    close(clientSocket);
    ((Server*)server)->clientDisconnected();
    std::cout << "Client (" << clientSocket << ") Disconnected. "
                                               "(Active Clients: " << ((Server*)server)->getClientsStatus() << ")" << std::endl;
}

int ClientHandler::getClientSock() const {return clientSocket;}

ClientData& ClientHandler::getClientData() {return clientData;}