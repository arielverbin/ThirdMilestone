
#ifndef THIRDMILESTONE_SERVER_H
#define THIRDMILESTONE_SERVER_H

#include <netinet/in.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include <iostream>
#include <pthread.h>
#include "../IO/DefaultIO.h"
#include "../IO/SocketIO.h"
#include "CLI.h"
#include "ClientHandler.h"
/**
 * Handles the acceptance of clients and send their socket fds to a CLI class.
 */
class Server {
private:
    //max amount of clients.
    const int maxClients;

    //address of socket.
    struct sockaddr_in socketAddress;

    //Server socket fd, current amount fo clients.
    int sock, numClients;

    /**
     * Binds the new socket to a socket address.
     * @param port the port (as part of the socket address).
     */
    void bind(int port);

    /**
     * Announce willingness to accept connections.
     */
    void listen() const;
    /**
     * Starts the ClientHandler.
     * @param clientHandler.
     * @return status of thread (nullptr).
     */
    static void* serveClient(void* clientHandler);

public:
    /**
     * Constructor.
     * @param port the port that the server will be bound to.
     * @param maxClients the maximum clients the server can handle at the same time.
     */
    Server(int port, int maxClients);

    /**
     * accepts clients until timeout.
     * @return true if timeout occurred, false if some error.
     */
    bool acceptClients();

    /**
     * closes the server (does not affect connected clients, until they disconnect).
     */
    void closeServer() const;

    /**
     * Let the server know that a client have disconnected (Used by ClientHandler).
     */
    void clientDisconnected();

    /**
     * @return (a/b) where a is the number of current clients and b is the max amount of clients.
     */
    std::string getClientsStatus() const;


};


#endif //THIRDMILESTONE_SERVER_H
