#ifndef THIRDMILESTONE_SERVERSRC_COMMANDS_SETPARAMETERS_H
#define THIRDMILESTONE_SERVERSRC_COMMANDS_SETPARAMETERS_H

#include "Command.h"
#include <iostream>
#include <fstream>

/**
 * @brief command 2 - show the current KNN parameters.
 * 
 */
class SetParameters : public Command {
public:
    explicit SetParameters(DefaultIO &io);

    void execute(ClientData cd) override;
};

#endif //THIRDMILESTONE_SERVERSRC_COMMANDS_SETPARAMETERS_H