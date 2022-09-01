#ifndef THIRDMILESTONE_SERVERSRC_COMMANDS_CLASSIFYDATA_H
#define THIRDMILESTONE_SERVERSRC_COMMANDS_CLASSIFYDATA_H

#include "Command.h"
#include <iostream>
#include <fstream>

/**
 * @brief command 3 - classify the data.
 * 
 */
class ClassifyData : public Command {
public:
    explicit ClassifyData(DefaultIO &io);

    bool execute(ClientData& cd) override;
};

#endif //THIRDMILESTONE_SERVERSRC_COMMANDS_CLASSIFYDATA_H