#ifndef THIRDMILESTONE_SERVERSRC_COMMANDS_COMMAND_H
#define THIRDMILESTONE_SERVERSRC_COMMANDS_COMMAND_H

#include "../../IO/DefaultIO.h"
#include "../ClientData.h"
#include <string>

/**
 * @brief the abstract class for the commands
 * 
 */
class Command {
protected:
    //the description of the command
    std::string description;

    DefaultIO &defaultIO;

    Command(DefaultIO &io, std::string description);

public:
    /**
     * Execute the command.
     * @param cd the command has access to the client's data.
     */
    virtual void execute(ClientData cd) = 0;

    /**
     * @return the description of the command (what it does).
     */
    std::string getDescription();
};

#endif //THIRDMILESTONE_SERVERSRC_COMMANDS_COMMAND_H