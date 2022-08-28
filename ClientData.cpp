#include "ClientData.h";

 ClientData::ClientData(){
    K = 5;
    destanceMetric = "EUC";
}

std::string ClientData::getTestFile(){
    return testFile;
}

void ClientData::setTestFile(std::string file1){
    testFile = file1;
}


std::string ClientData::getTrainFile(){
    return trainFile;
}

void ClientData::setTrainFile(std::string file2){
    trainFile = file2;
}


std::string ClientData::getDestanceMetric(){
    return destanceMetric;
}

void ClientData::setDestanceMetric(std::string newMatric){
    destanceMetric = newMatric;
}

int ClientData::getK(){
    return K;
}

void ClientData::setK(int k1){
    K = k1;
}

// int** ClientData::getMatrix(){
//     return matrix;
// }

// void ClientData::setMatrix(int** matrix1){
//     matrix = matrix1;
// }