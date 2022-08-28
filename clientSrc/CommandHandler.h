
#ifndef THIRDMILESTONE_COMMANDHANDLER_H
#define THIRDMILESTONE_COMMANDHANDLER_H

#include "../IO/DefaultIO.h"
#include "../IO/StandardIO.h"
#include "../IO/FileIO.h"
/**
 * Can analyze the server's instructions and execute them.
 */
class CommandHandler {
private:
    //The communication method with the server.
    DefaultIO& serverIO;
    //The communication method with the client.
    StandardIO screenIO;
public:
    explicit CommandHandler(DefaultIO& defaultIo);
    /**
     * Handles the server's commands.
     */
    void handle();
};


#endif //THIRDMILESTONE_COMMANDHANDLER_H
