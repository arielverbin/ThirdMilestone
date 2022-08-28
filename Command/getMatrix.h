#include "CommandAbstract.h"
#include <iostream>
#include <fstream>

/**
 * @brief command 6 - calculate the confusion matrix.
 * 
 */
class getMatrix : public CommandAbstract {
    public:
        void execute() override;
};