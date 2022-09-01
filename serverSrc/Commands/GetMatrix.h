#ifndef THIRDMILESTONE_SERVERSRC_COMMANDS_GETMATRIX_H
#define THIRDMILESTONE_SERVERSRC_COMMANDS_GETMATRIX_H

#include "Command.h"
#include <iostream>
#include <fstream>
#include "../ClientData.h"

/**
 * @brief command 6 - calculate the confusion matrix.
 * 
 */
class GetMatrix : public Command {
public:
    explicit GetMatrix(DefaultIO& io);
    /**
    * @brief call the calculate function and than to addToBiggestDecimal. At last it send the matrix as a string.
    *
    * @param cd
    */
    bool execute(ClientData &cd) override;

};


#endif //THIRDMILESTONE_SERVERSRC_COMMANDS_GETMATRIX_H