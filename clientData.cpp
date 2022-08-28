#include "clientData.h";

 clientData::clientData(){
    K = 5;
    destanceMetric = "EUC";
}

std::string clientData::getTestFile(){
    return testFile;
}

void clientData::setTestFile(std::string file1){
    testFile = file1;
}


std::string clientData::getTrainFile(){
    return trainFile;
}

void clientData::setTrainFile(std::string file2){
    trainFile = file2;
}


std::string clientData::getDestanceMetric(){
    return destanceMetric;
}

void clientData::setDestanceMetric(std::string newMatric){
    destanceMetric = newMatric;
}

int clientData::getK(){
    return K;
}

void clientData::setK(int k1){
    K = k1;
}

// int** clientData::getMatrix(){
//     return matrix;
// }

// void clientData::setMatrix(int** matrix1){
//     matrix = matrix1;
// }