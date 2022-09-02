#ifndef THIRDMILESTONE_SERVERSRC_COMMANDS_GETMATRIX_H
#define THIRDMILESTONE_SERVERSRC_COMMANDS_GETMATRIX_H

#include "Command.h"
#include <iostream>
#include <fstream>
#include "../ClientData.h"
#include "KNN/Point.h"
#include "KNN/Flowers/Flower.h"
#include "KNN/KNNClassifier.h"
#include "KNN/DistanceCalcs/ChebyshevDistance.h"
#include "KNN/DistanceCalcs/EuclideanDistance.h"
#include "KNN/DistanceCalcs/ManhattanDistance.h"
#include "KNN/DistanceCalcs/DistanceCalculator.h"
#include "KNN/KNNFileClassifier.h"

/**
 * @brief command 6 - calculate the confusion matrix.
 *
 */
class GetMatrix : public Command {
public:
    /**
    * @brief Get the Matrix object
    *
    * @param io reference to the method of communication.
    */
    explicit GetMatrix(DefaultIO &io);


    /**
     * @brief call the calculate function and than to addToBiggestDecimal. At last it send the matrix as a string.
    *
    * @param cd access to the client's data.
     */
    bool execute(ClientData &cd) override;

private:
    /**
     * Fill amounts of points of class i, that was classified to be class j. i,j {1,2,3}.
     * @param matrix where to save the results.
     * @param test the j's (classified).
     * @param toTest the i (actual).
     */
    static void fillCountTypeMatrix(int matrix[3][3], std::vector<Flower> &test, std::vector<Flower> &toTest);

    /**
     * Count how many of each type in the actuals.
     * @param counts the array to save the result.
     * @param test the actuals.
     */
    static void fillCountEachType(int *counts, std::vector<Flower> &test);

};


#endif //THIRDMILESTONE_SERVERSRC_COMMANDS_GETMATRIX_H