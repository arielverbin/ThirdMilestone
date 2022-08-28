#include "CommandAbstract.h"
#include <iostream>
#include <fstream>

/**
 * @brief command 2 - show the current KNN parameters.
 * 
 */
class showParameters : public CommandAbstract {
    public:
        void execute() override;
};