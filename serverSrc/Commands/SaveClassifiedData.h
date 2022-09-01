#ifndef THIRDMILESTONE_SERVERSRC_COMMANDS_SAVECLASSIFIEDDATA_H
#define THIRDMILESTONE_SERVERSRC_COMMANDS_SAVECLASSIFIEDDATA_H

#include "Command.h"
#include <iostream>
#include <fstream>
#include "../KNN/Flowers/Flower.hpp"

/**
 * @brief command 5 - save the classified data.
 * 
 */
class SaveClassifiedData : public Command {
public:
    explicit SaveClassifiedData(DefaultIO &io);

    void execute(ClientData cd) override;
};
#endif //THIRDMILESTONE_SERVERSRC_COMMANDS_SAVECLASSIFIEDDATA_H