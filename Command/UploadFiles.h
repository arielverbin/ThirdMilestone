#include "CommandAbstract.h"
#include <iostream>
#include <fstream>

/**
 * @brief command 1 - upload a file to the server
 * 
 */
class UploadFiles : public CommandAbstract {
    public:
        void execute() override;
};