#include "DefaultIO.h"

/**
 * @brief the abstract class for the commands
 * 
 */
class Command {
    protected:
        //the description of the command
        std::string description;
        
        DefaultIO& defaultIO;
        explicit Command(DefaultIO& io) : defaultIO(io){}

    public:
        virtual void execute() = 0;
        std::string getDescription() {return description;}
        
};