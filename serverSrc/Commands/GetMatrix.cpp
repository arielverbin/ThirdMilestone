#include "GetMatrix.h"
#include "KNN/Point.h"
#include "KNN/Flowers/Flower.h"
#include "KNN/DistanceCalcs/ChebyshevDistance.h"
#include "KNN/DistanceCalcs/EuclideanDistance.h"
#include "KNN/DistanceCalcs/ManhattanDistance.h"
#include "KNN/DistanceCalcs/DistanceCalculator.h"
#include "KNN/KNNFileClassifier.h"
#include <vector>

GetMatrix::GetMatrix(DefaultIO &io) : Command(io, "display algorithm confusion matrix"){}

bool GetMatrix::execute(ClientData &cd) {
    std::vector<Point> unclassifiedPoints = Point::toPoints(cd.getTestFile(), '\n'); //unclassified.
    std::vector<Flower> classifiedPoints = Flower::toFlowers(cd.getTrainFile(), '\n'); //database.

    DistanceCalculator *distanceMetric;
    if(cd.getDistanceMetric() == "MAN") distanceMetric = new ManhattanDistance;
    else if(cd.getDistanceMetric() == "EUC") distanceMetric = new EuclideanDistance;
    else distanceMetric = new ChebyshevDistance;

    KNNFileClassifier knnFileClassifier;
    std::vector<Flower> classified = knnFileClassifier.classify(cd.getK(), //k
                                                                unclassifiedPoints, //unclassified
                                                                classifiedPoints, //database
                                                                distanceMetric); //metric
    delete distanceMetric;
    return true;
}