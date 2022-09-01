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
private:
    /**
     * Report to client that he gave invalid input (and ask him to send again).
     * @param mes the message of invalid.
     */
    void reportInvalidInput(const std::string& mes);
public:
    explicit SetParameters(DefaultIO &io);

    bool execute(ClientData& cd) override;
};

#endif //THIRDMILESTONE_SERVERSRC_COMMANDS_SETPARAMETERS_H