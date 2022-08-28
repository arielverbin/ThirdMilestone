#include "CommandAbstract.h"
#include <iostream>
#include <fstream>

/**
 * @brief command 4 - print classified data to the screen.
 * 
 */
class printClassifiedData : public CommandAbstract {
    public:
        void execute(clientData cd) override;
};