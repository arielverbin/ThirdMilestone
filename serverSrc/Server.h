
#ifndef THIRDMILESTONE_SERVER_H
#define THIRDMILESTONE_SERVER_H

#include <netinet/in.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include <iostream>
#include "pthread.h"
#include "../IO/DefaultIO.h"
#include "../IO/SocketIO.h"
#include "CLI.h"
#include "ClientHandler.h"
#include "Timeout.h"

/**
 * Handles the acceptance of clients and send their socket fds to a CLI class.
 */
class Server {
private:
    //max amount of clients.
    const int maxClients;

    //address of socket.
    struct sockaddr_in socketAddress;

    //Server socket fd, current amount fo clients, port of server.
    int sock, numClients, port;
    //vector of actives threads (their id's).
    std::vector<pthread_t> threadsID;

    //class Timeout will change this boolean, so we know not to serve the connection.
    bool timeoutPassed;

    /**
     * Binds the new socket to a socket address.
     */
    void bind();

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
    /**
     * Starts the timeout for the accept function.
     * @param instance instance of class "Timeout"
     * @return nullptr.
     */
    static void* startTimeout(void* instance);
    /**
     * Accept new clients and close them immediately (used after timeout).
     * @param sock socket of server.
     * @return nothing.
     */
    static void* blockNewClients(void* sock);

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
