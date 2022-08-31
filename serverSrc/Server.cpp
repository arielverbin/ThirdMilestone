#include "Server.h"

pthread_mutex_t key; //mutex lock.

Server::Server(int port, int maxClients) : socketAddress{}, maxClients(maxClients), port(port) {
    this->numClients = 0;
    this->sock = socket(AF_INET, SOCK_STREAM, 0); //create a new socket - IPv4, TCP.
    if (this->sock < 0) {
        perror("Error creating socket for server.");
        exit(1);
    }
    this->bind();
    this->listen();

    this->numClients = 0;
}

void Server::bind() {
    memset(&socketAddress, 0, sizeof(this->socketAddress));
    this->socketAddress.sin_family = AF_INET; //family (TCP)
    this->socketAddress.sin_addr.s_addr = INADDR_ANY;//IP - on our local machine.
    this->socketAddress.sin_port = htons(port); //selected port.

    //bind new socket to selected socked address.
    if (::bind(this->sock, (struct sockaddr *) &socketAddress, sizeof(socketAddress)) < 0) {
        perror("Error binding socket to given socket address");
        close(sock);
        exit(1);
    }
}

void Server::listen() const {
    if (::listen(this->sock, this->maxClients) < 0) {
        perror("Error listening to a socket");
        close(sock);
        exit(1);
    }
}
void* Server::serveClient(void* clientHandler){
    ClientHandler& ch= *(ClientHandler*)clientHandler;
    SocketIO defaultIO(ch.getClientSock()); //can be switched to another DefaultIO.

    DefaultIO& io = defaultIO;
    CLI cli(io, ch.getClientData());
    ch.serveWith(cli); //serve the client via Commands Line Interface.
    // ClientHandler can serve with any class with "CLI::start" command. Therefore, CLI may become abstract if we
    // would want to support multiple types of serving.
    return nullptr; //delete the thread.
}
void* Server::startTimeout(void* instance){
    Timeout *timeout = ((Timeout*) instance);
    timeout->count();
    return nullptr;
}
bool Server::acceptClients() {
    pthread_t id, idOfTimeout;
    Timeout timeout(15, port);

    while(true){
        if (numClients >= maxClients) {
            std::cout << "[!] Client acceptance is blocked until a disconnection occurs." << std::endl;
            while(numClients >= maxClients){}
        } //wait until new connections are available.

        struct sockaddr_in client_sin{}; //new socked address of new client.
        unsigned int addr_len = sizeof(client_sin);

        //wait until a client connects. then, create a new socket.
        pthread_create(&idOfTimeout, nullptr, startTimeout, &timeout); //start timeout.
        int clientSock = accept(this->sock, (struct sockaddr *) &client_sin, &addr_len);
        pthread_cancel(idOfTimeout); //cancel timeout because accept was finished.

        if (clientSock < 0) { perror("[!] Error accepting"); continue;}

        std::string identifier = SocketIO(clientSock).receive(); //identifying connection.
        if(identifier == "<timeout>") {
            std::cout << "[TIMEOUT] Clients can no longer connect." << std::endl;
            close(clientSock); break;
        } if(identifier == "<error>") {
            std::cout  << "[!] Error identifying connection (Timeout restarted)." << std::endl; continue;}

        //this is a client.
        this->numClients++;
        this->threadsID.emplace_back(id);
        std::cout << "# New client (" << clientSock << ") connected. "
                                      "(Active Clients: " << this->getClientsStatus() << ")."<< std::endl;
        ClientHandler clientHandler{this, clientSock}; //serve the client.
        pthread_create(&id, nullptr, serveClient, &clientHandler); //serve the client via a new thread.
    }
    return true;
}

void Server::closeServer() const {
    if(numClients > 0) {
        std::cout << "# Wait for active clients to finish..." << std::endl;
        for (const pthread_t &id: threadsID) {
            pthread_join(id, nullptr);
        }
        std::cout << "# The last client has disconnected.";
    }
    std::cout << "# Closing Server..." << std::endl;
    close(sock);
}

void Server::clientDisconnected() {
    pthread_mutex_lock(&key); //must be locked because numClients is a shared resource.
    this->numClients--;
    pthread_mutex_unlock(&key);
}

std::string Server::getClientsStatus() const{
    return std::to_string(numClients) + "/" + std::to_string(maxClients);
}