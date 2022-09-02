#include "GetMatrix.h"
#include <vector>
#include <iostream>

GetMatrix::GetMatrix(DefaultIO &io) : Command(io, "display algorithm confusion matrix") {}

void GetMatrix::fillCountTypeMatrix(int matrix[3][3], std::vector<Flower> &test, std::vector<Flower> &toTest) {
    for (int i = 0; i < test.size(); i++) {
        if (test[i].getType() == "Iris-setosa" && toTest[i].getType() == "Iris-setosa") matrix[0][0]++;
        else if (test[i].getType() == "Iris-setosa" && toTest[i].getType() == "Iris-versicolor") matrix[0][1]++;
        else if (test[i].getType() == "Iris-setosa" && toTest[i].getType() == "Iris-virginica") matrix[0][2]++;

        else if (test[i].getType() == "Iris-versicolor" && toTest[i].getType() == "Iris-versicolor") matrix[1][1]++;
        else if (test[i].getType() == "Iris-versicolor" && toTest[i].getType() == "Iris-setosa") matrix[1][0]++;
        else if (test[i].getType() == "Iris-versicolor" && toTest[i].getType() == "Iris-virginica") matrix[1][2]++;

        else if (test[i].getType() == "Iris-virginica" && toTest[i].getType() == "Iris-setosa") matrix[2][0]++;
        else if (test[i].getType() == "Iris-virginica" && toTest[i].getType() == "Iris-versicolor") matrix[2][1]++;
        else matrix[2][2]++;
    }
}

void GetMatrix::fillCountEachType(int *counts, std::vector<Flower> &test) {
    for (Flower &flower: test) {
        if (flower.getType() == "Iris-setosa") counts[0]++;
        else if (flower.getType() == "Iris-versicolor") counts[1]++;
        else if (flower.getType() == "Iris-virginica") counts[2]++;
    }
}

void incBiggestDecimal(int result[3][3], int i, float matrix[3][3]) {
    int iMAX = i, jMAX = 0;
    float decimal = matrix[0][0] - (float)result[0][0];
    for (int j = 0; j < 3; j++) {
        if (matrix[i][j] - (float)result[i][j] > decimal) {
            decimal = matrix[i][j] - (float)result[i][j];
            iMAX = i;
            jMAX = j;
        }
    }
    result[iMAX][jMAX]++;
    matrix[iMAX][jMAX] = (float) ((int) matrix[iMAX][jMAX]); //changing decimal to 0.
}

bool GetMatrix::execute(ClientData &cd) {
    if (cd.getTrainFile() == "<empty>") {
        defaultIO.send("<# Please upload CSV files first.\n>[screen_print]");
        return true;
    }
    if(cd.getConfusionMatrix() != "<empty>"){
        defaultIO.send(cd.getConfusionMatrix() +"[screen_print]<# Press Enter.>[screen_print][screen_read]");
        return true;
    }

    std::vector<Flower> trainTest = Flower::toFlowers(cd.getTrainFile(), '\n');
    KNNFileClassifier knnFileClassifier;

    std::vector<Point> trainToClass;
    for (Flower &flower: trainTest) {
        trainToClass.emplace_back(flower.getPoint()); //get only-points from train.
    }
    DistanceCalculator *distanceCalculator;
    if (cd.getDistanceMetric() == "CHE") distanceCalculator = new ChebyshevDistance;
    else if (cd.getDistanceMetric() == "MAN") distanceCalculator = new ManhattanDistance;
    else distanceCalculator = new EuclideanDistance;
    std::vector<Flower> toTest = knnFileClassifier.classify(cd.getK(), trainToClass, trainTest, distanceCalculator);

    delete distanceCalculator;

    if(toTest[0].getType() == "<error>") {
        defaultIO.send("<# Error in displaying Confusion Matrix. "
                       "Try uploading different files.\n>[screen_print]");
        return true;
    }

    int countTypeMatrix[3][3] = {0};
    //countTypeMatrix[i][j] will store amount of points that are of class i, but classified to j.
    fillCountTypeMatrix(countTypeMatrix, trainTest, toTest);
    int countEachType[3] = {0};
    //countEachType[i] will store amount of points that are of class i.
    fillCountEachType(countEachType, trainTest);

    float matrix[3][3]; //precise matrix (using float)
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matrix[i][j] = (((float)countTypeMatrix[i][j] / (float) countEachType[i]) * 100);
        }
    }
    int result[3][3]; //rounded matrix (narrowing to int)
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result[i][j] = (int)matrix[i][j];
        }
    }
    for (int i = 0; i < 3; i++) { //complete to 100% (might be necessary due to rounding)
        int error = 0;
        for (int j = 0; j < 3; j++) {
            error += result[i][j];
        }
        error = 100 - error;
        for (int k = 0; k < error; k++) {
            incBiggestDecimal(result, i, matrix);
        }
    }
    cd.setConfusionMatrix("<\n"
    "Iris-setosa    |\t" + std::to_string(result[0][0]) + "%\t\t" + std::to_string(result[0][1]) + "%\t\t" +
    std::to_string(result[0][2]) + "%\n" +
    "Iris-versicolor|\t" + std::to_string(result[1][0]) + "%\t\t" + std::to_string(result[1][1]) + "%\t\t" +
    std::to_string(result[1][2]) + "%\n" +
    "Iris-virginica |\t" + std::to_string(result[2][0]) + "%\t\t" + std::to_string(result[2][1]) + "%\t\t" +
    std::to_string(result[2][2]) + "%\n" +
    "               ---------------------------------------------------\n"
    "               Iris-setosa\t" + "Iris-versicolor\t" + "Iris-virginica\n\n" +

    "# K = " + std::to_string(cd.getK()) + "  Metric method = " + cd.getDistanceMetric() + "\n>");

    defaultIO.send(cd.getConfusionMatrix() +"[screen_print]<# Press Enter.>[screen_print][screen_read]");
    return true;
}
