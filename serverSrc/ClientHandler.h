
#ifndef THIRDMILESTONE_CLIENTHANDLER_H
#define THIRDMILESTONE_CLIENTHANDLER_H

#include "CLI.h"
#include "ClientData.h"
#include "Server.h"
/**
 * Starts communication between server and clients, via a CLI.
 */
class ClientHandler {
private:
    //The server that owns the ClientHandler (To which the client is connected to).
    Server* server;
    ClientData clientData;
    //The client.
    int clientSocket;
public:
    /**
     * Constructor.
     * @param server the server to which the client is connected to.
     * @param clientSock the client.
     */
    ClientHandler(void* server, int clientSock);
    /**
     * Serve the client with CLI that supports communication (with DefaultIO).
     * @param cli the CLI.
     */
    void serveWith(CLI& cli) const;
    /**
     * Disconnect from the server eventually.
     */
    void disconnect() const;
    /**
     * @return the socket fd of the client.
     */
    int getClientSock() const;

    ClientData& getClientData();
};


#endif //THIRDMILESTONE_CLIENTHANDLER_H
