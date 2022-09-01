#ifndef THIRDMILESTONE_CLI_H
#define THIRDMILESTONE_CLI_H

#include <netinet/in.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include <iostream>
#include "Commands/Command.h"
#include "Commands/UploadFiles.h"
#include "Commands/ClassifyData.h"
#include "Commands/GetMatrix.h"
#include "Commands/PrintClassifiedData.h"
#include "Commands/SaveClassifiedData.h"
#include "Commands/SetParameters.h"
#include "../IO/DefaultIO.h"
#include "../IO/StandardIO.h"
#include "../IO/SocketIO.h"
#include <vector>

/**
 * This class is responsible for way that the server communicates with the clients.
 * This class is activated by ClientHandler, and determines what services the Server offers (Commands 1-7).
 */
class CLI {
private:
    /**
     * @return the menu of commands that the CLI offers.
     */
    std::string getMenu() const;
    //The method of communication with the client.
    DefaultIO& io;
    //the CLI has access to the client data.
    ClientData& clientData;
    //The list of commands available.
    std::vector<Command*> commands;
public:
    /**
     * Constructor.
     * @param defaultIo method of communication.
     */
    CLI(DefaultIO& defaultIo, ClientData& cd);
    /**
     * Start the communication.
     */
    void start() const;

    virtual ~CLI();
};


#endif //THIRDMILESTONE_CLI_H
