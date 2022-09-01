#ifndef THIRDMILESTONE_SERVERSRC_COMMANDS_UPLOADFILES_H
#define THIRDMILESTONE_SERVERSRC_COMMANDS_UPLOADFILES_H

#include "Command.h"
#include "ClientData.h"
#include <iostream>
#include <fstream>
#include <string>

/**
 * @brief command 1 - upload a file to the server
 * 
 */

class UploadFiles : public Command {
private:
    static void save(ClientData cd, std::string testFile, std::string trainFile);

public:
    explicit UploadFiles(DefaultIO &io);

    void execute(ClientData cd) override;
};

#endif //THIRDMILESTONE_SERVERSRC_COMMANDS_UPLOADFILES_H