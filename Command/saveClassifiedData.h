#include "CommandAbstract.h"
#include <iostream>
#include <fstream>

/**
 * @brief command 5 - save the classified data.
 * 
 */
class saveClassifiedData : public CommandAbstract {
    public:
        void execute(clientData cd) override;
};