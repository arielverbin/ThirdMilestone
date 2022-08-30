
#ifndef THIRDMILESTONE_CLIENT_H
#define THIRDMILESTONE_CLIENT_H

#include "../IO/SocketIO.h"
#include "CommandHandler.h"
#include <netinet/in.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include <iostream>
#include <arpa/inet.h>
/**
 * A client can connect to a Server and display its services via "CommandHandler".
 */
class Client {
private:
    int socket;
    bool connected;
public:
    Client();
    /**
     * Connect to a server.
     * @param serverPort the server's port.
     */
    bool connectTo(int serverPort);
    /**
     * Show the server's command options and communicate with the server.
     * If the client isn't connected the method will do nothing.
     */
    void getService() const;
    /**
     * Disconnects from server. (if the client isn't connected the method will do nothing).
     */
    void disconnect();


};


#endif //THIRDMILESTONE_CLIENT_H
