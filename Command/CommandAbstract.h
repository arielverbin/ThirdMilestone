#include "DefaultIO.h"

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
        virtual void execute() = 0;
        
};