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
/**
 * @brief Get the Matrix object
 * 
 * @param io 
 */
    explicit GetMatrix(DefaultIO &io);


/**
 * @brief call the calculate function and than to addToBiggestDecimal. At last it send the matrix as a string.
 * 
 * @param cd 
 */
    void execute(ClientData cd) override;


/**
 * @brief use the addToBiggestDecimal function. give us the "percent matrix" and the "decimal matrix"
 * addToBiggestDecimal gives us a matrix with numbers, not percents.
 * 
 * @param cd 
 * @param decimalMatrix 
 * @return int** 
 */
int** calculate(ClientData cd, float** decimalMatrix);




/**
 * @brief get the output file - the types and return an array[n] -> array[i] = 1 or 2 or 3 
 *          if the type i is Iris-virginica, Iris-setosa, Iris-versicolor respectively.
 * 
 * @param string 
 * @return int* 
 */
    int* countType(std::string string);


/**
 * @brief calculate an helper matrix - helper[i][j] = the *number* of 'flowers' that from type i 
 *          but classified to j.  return the helper matrix.
 * 
 * @param cd 
 * @return int** - return the helper matrix.
 */
    int** getTypeCountMatrix(ClientData cd);



/**
 * @brief because we use int for the matrix, maybe the sum of the percents wont be 100, so
 * we add the difference (100 - sum) to the slots with the biggest decimal. 
 * For example, if a line in the matrix should be : [50.6   20    29.4]
 * in our matrix (int) it will be : [50   20   29]  and the sum is 99, so we add the differene (1)
 * to the number with the biggest decimal - 50 (0.6) ->   [*51*  20   29].
 * After that the function zero the decimal we used (in this case 0.6).
 * 
 * If the difference is x > 1 , we will call the function x times.  
 * 
 * @param decimal the decimal line - we used it to know which number has the biggest decimal
 * @param matrix the int matrix
 */
    void addToBiggestDecimal(float* decimal, int* matrix);

};


#endif //THIRDMILESTONE_SERVERSRC_COMMANDS_GETMATRIX_H