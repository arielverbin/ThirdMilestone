#ifndef THIRDMILESTONE_SERVERSRC_COMMANDS_PRINTCLASSIFIEDDATA_H
#define THIRDMILESTONE_SERVERSRC_COMMANDS_PRINTCLASSIFIEDDATA_H

#include "Command.h"
#include <iostream>
#include <fstream>
#include "../KNN/Flowers/Flower.hpp"

/**
 * @brief command 4 - print classified data to the screen.
 * 
 */
class PrintClassifiedData : public Command {
public:
    explicit PrintClassifiedData(DefaultIO &io);

    void execute(ClientData cd) override;
};

#endif //THIRDMILESTONE_SERVERSRC_COMMANDS_PRINTCLASSIFIEDDATA_H