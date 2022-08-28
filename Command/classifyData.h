#include "CommandAbstract.h"
#include <iostream>
#include <fstream>

/**
 * @brief command 3 - classify the data.
 * 
 */
class classifyData : public CommandAbstract {
    public:
        void execute() override;
};