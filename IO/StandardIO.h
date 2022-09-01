
#ifndef THIRDMILESTONE_STANDARDIO_H
#define THIRDMILESTONE_STANDARDIO_H

#include "DefaultIO.h"
#include <iostream>
/**
 * Send (print) data to the screen, and receive data from the screen (typing input in runtime).
 */
class StandardIO : public DefaultIO{
public:
    std::string receive() override;
    bool send(std::string message) override;
};


#endif //THIRDMILESTONE_STANDARDIO_H
