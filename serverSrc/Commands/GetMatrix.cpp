#include "GetMatrix.h"

GetMatrix::GetMatrix(DefaultIO &io) : Command(io, "display algorithm confusion matrix"){}

void GetMatrix::execute(ClientData cd) {
    
    float** decimalMatrix = new float*[3];
    for (int i = 0; i < 3; i++){
        decimalMatrix[i] = new float[3];
    }

    int** matrix = calculate(cd, decimalMatrix);

    for (int i = 0; i < 3; i++){
        int x = 100 - (matrix[i][0] + matrix[i][1] + matrix[i][2]);
        addToBiggestDecimal(decimalMatrix[i], matrix[i]);
    }

    for (int i = 0; i < 3; i++){
        delete decimalMatrix[i];
    } 
    delete decimalMatrix;

    defaultIO.send("<Iris-setosa    " + std::to_string(matrix[0][0]) + "%    " + std::to_string(matrix[0][1]) + "%    " + std::to_string(matrix[0][2]) + "%\n" +
    "Iris-versicolor    " + std::to_string(matrix[1][0]) + "%    " + std::to_string(matrix[1][1]) + "%    " + std::to_string(matrix[1][2]) + "%\n" +
    "Iris-virginica    " + std::to_string(matrix[2][0]) + "%    " + std::to_string(matrix[2][1]) + "%    " + std::to_string(matrix[2][2]) + "%\n" +
    "Iris-setosa    " +"Iris-versicolor    " + "Iris-virginica\n" +
    "K = " + std::to_string(cd.getK()) + "  metric = " + cd.getDistanceMetric() + ">[screen_print]");

    for (int i = 0; i < 3; i++){
        delete matrix[i];
    } 
    delete matrix;
};



int** calculate(ClientData cd, float** decimal){
    int** helperMatrix = getTypeCountMatrix(cd);
    int** matrix = new int*[3];
    for (int i = 0; i < 3; i++){
        matrix[i] = new int[3];
    }
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            matrix[i][j] = (helperMatrix[i][j] / (helperMatrix[i][0] + helperMatrix[i][1] + helperMatrix[i][2])) * 100;
        }
    }
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            decimal[i][j] = ((helperMatrix[i][j] / (helperMatrix[i][0] + helperMatrix[i][1] + helperMatrix[i][2])) * 100) - matrix[i][j];
        }
    }
    for (int i = 0; i < 3; i++){
        delete helperMatrix[i];
    } 
    delete helperMatrix;
    return matrix;
}

int* countType(std::string string){
    // int* count = new int[3];
    int start1 = 0;
    int end1 = (int)string.find('\n');
    int i = 0;
    int countNumber = 0;
    while (end1 != -1) {
        countNumber++;
        i++;
        start1 = end1 + 1;
        end1 = (int)string.find('\n', start1);
    }
    int* arrayType = new int[countNumber];

    int start = 0;
    int end = (int)string.find('\n');
    int i = 0;
    int j = 0;
    while (end != -1) {
        if (string.substr(start, end - start).compare("Iris-setosa")){
            arrayType[j] = 1;
        }
        else if (string.substr(start, end - start).compare("Iris-versicolor")){
            arrayType[j] = 2;
        }
        else 
            arrayType[j] = 3;
        j++;
        i++;
        start = end + 1;
        end = (int)string.find('\n', start);
    }
    return arrayType;
    
}

int** getTypeCountMatrix(ClientData cd){
    int** matrix = new int*[3];
    for (int i = 0; i < 3; i++){
        matrix[i] = new int[3];
    }
    int* countTypesTrain = countType(cd.getTrainFile());
    int* countTypesClassified = countType(cd.getClassifies());

    // for (int i = 0; i < 3; ++i) {
    //     countTypesTrain[i] = countType(cd.getTrainFile())[i];
    // }
    // for (int i = 0; i < 3; ++i) {
    //     countTypesClassified[i] = countType(cd.getClassifies())[i];
    // }

    for (int i = 0; i < 3; i++){
        if (countTypesTrain[i] == 1 && countTypesClassified[1] == 1){
            matrix[0][0] += 1;
        }
        else if (countTypesTrain[i] == 1 && countTypesClassified[1] == 2){
            matrix[0][1] += 1;
        }
        else if (countTypesTrain[i] == 1 && countTypesClassified[1] == 3){
            matrix[0][2] += 1;
        }
        else if (countTypesTrain[i] == 2 && countTypesClassified[1] == 1){
            matrix[1][0] += 1;
        }
        else if (countTypesTrain[i] == 2 && countTypesClassified[1] == 2){
            matrix[1][1] += 1;
        }
        else if (countTypesTrain[i] == 2 && countTypesClassified[1] == 3){
            matrix[1][2] += 1;
        }
        else if (countTypesTrain[i] == 3 && countTypesClassified[1] == 1){
            matrix[2][0] += 1;
        }
        else if (countTypesTrain[i] == 3 && countTypesClassified[1] == 2){
            matrix[2][1] += 1;
        }
        else 
            matrix[2][2] += 1; 
    }
    delete countTypesClassified;
    delete countTypesTrain;
    return matrix;
}


void addToBiggestDecimal(float* decimal, int* matrix){
    if (decimal[0] > decimal[1]){
        if (decimal[0] > decimal[2]){
            matrix[0]++;
            decimal[0] = 0;
        }
        else
            matrix[2]++;
            decimal[2]++;
    }
    else if (decimal[1] > decimal[2]){
        matrix[1]++;
        decimal[1] = 0;        
    }
    else {
    matrix[2]++;
    decimal[2] = 0;            
    }
}



