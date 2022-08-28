#include "DefaultIO.h"
#include "clientData.h"

/**
 * @brief the abstract class for the commands
 * 
 */
class CommandAbstract {
    protected:
    //the description of the command
        std::string description;
        
        DefaultIO& defaultIO;

    public:
        CommandAbstract();
        virtual void execute(clientData cd) = 0;
        std::string getDescription();
        
};