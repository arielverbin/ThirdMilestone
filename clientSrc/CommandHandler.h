
#ifndef THIRDMILESTONE_COMMANDHANDLER_H
#define THIRDMILESTONE_COMMANDHANDLER_H

#include "../IO/DefaultIO.h"
#include "../IO/StandardIO.h"
#include "../IO/FileIO.h"
#include <stack>
#include <string>
#include "pthread.h"
/**
 * Can analyze the server's instructions and execute them.
 */
class CommandHandler {
private:
    //The communication method with the server.
    DefaultIO& serverIO;
    //The communication method with the client.
    StandardIO screenIO;
    //buffer, used to store data for a short amount of time (while following the server's instructions).
    std::string buffer;
    /**
     * Converts the instructions received from the server as string, to a stack of instructions.
     * FOR EXAMPLE: <hello>[this][is]<example> --TO--> [{<example>, [is], [this], <hello>}
     * @param raw the message from the server.
     * @return stack of instructions.
     */
    static std::stack<std::string> analyzeInstructions(std::string& raw);

    static void* saveFile(void* args);
public:
    /**
     * Constructor.
     * @param defaultIo the method of communication with the server.
     */
    explicit CommandHandler(DefaultIO& defaultIo);
    /**
     * Handles the server's commands.
     */
    void handle();
};


#endif //THIRDMILESTONE_COMMANDHANDLER_H
