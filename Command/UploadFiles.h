#include "CommandAbstract.h"
#include "clientData.h"
#include <iostream>
#include <fstream>

/**
 * @brief command 1 - upload a file to the server
 * 
 */
class UploadFiles : public CommandAbstract {
    public:
        UploadFiles();
        void execute(clientData cd) override;
        void save(clientData cd, string testFile, string trainFile);
};