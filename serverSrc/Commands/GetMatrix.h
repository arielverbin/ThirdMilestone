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
    explicit GetMatrix(DefaultIO &io);

    void execute(ClientData cd) override;

    int** calculate(ClientData cd, float** decimalMatrix);

    void toSend(ClientData cd, int** matrix, float** decimal);

    int* countType(std::string string);

    int** getTypeCountMatrix(ClientData cd);

    void addToBiggestDecimal(float* decimal, int* matrix);

};


#endif //THIRDMILESTONE_SERVERSRC_COMMANDS_GETMATRIX_H