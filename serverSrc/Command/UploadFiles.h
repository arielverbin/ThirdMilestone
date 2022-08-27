#include "Command.h"
#include <iostream>
#include <fstream>

/**
 * @brief command 1 - upload a file to the server
 * 
 */
class UploadFiles : public Command {
    public:
        explicit UploadFiles(DefaultIO& defaultIo);
        void execute() override;
};