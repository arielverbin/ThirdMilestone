#include "ClientData.h"

#include <utility>

ClientData::ClientData() :
                trainFile("<empty>"), testFile("<empty>"), classifiesFile("<empty>"),
                confusionMatrix("<empty>"){
    k = 5;
    distanceMetric = "EUC";
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

std::string& ClientData::getClassifiesFile() {
    return classifiesFile;
}

void ClientData::setClassifiesFile(std::string classified1) {
    classifiesFile = std::move(classified1);
}

void ClientData::setConfusionMatrix(std::string newMatrix) {
    confusionMatrix = std::move(newMatrix);
}

std::string& ClientData::getConfusionMatrix() {
    return confusionMatrix;
}
