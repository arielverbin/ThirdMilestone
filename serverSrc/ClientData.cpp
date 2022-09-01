#include "ClientData.h"

#include <utility>

ClientData::ClientData() : trainFile("<empty>"), testFile("<empty>"), classifiesFile("<empty>"){
    k = 5;
    distanceMetric = "EUC";
    confusionMatrix = nullptr;
}

std::string& ClientData::getTestFile() {
    return testFile;
}

void ClientData::setTestFile(std::string file1) {
    testFile = std::move(file1);
}


std::string& ClientData::getTrainFile() {
    return trainFile;
}

void ClientData::setTrainFile(std::string file2) {
    trainFile = std::move(file2);
}


std::string& ClientData::getDistanceMetric() {
    return distanceMetric;
}

void ClientData::setDistanceMetric(std::string newMetric) {
    distanceMetric = std::move(newMetric);
}

int ClientData::getK() const {
    return k;
}

void ClientData::setK(int k1) {
    k = k1;
}

int **ClientData::getConfusionMatrix() {
    return confusionMatrix;
}

std::string& ClientData::getClassifiesFile() {
    return classifiesFile;
}

void ClientData::setClassifiesFile(std::string classified1) {
    classifiesFile = std::move(classified1);
}

void ClientData::setConfusionMatrix(int **matrix1) {
    confusionMatrix = matrix1;
}