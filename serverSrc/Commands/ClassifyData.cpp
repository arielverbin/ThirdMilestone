#include "ClassifyData.h"
#include "KNN/Point.h"
#include "KNN/Flowers/Flower.h"
#include "KNN/DistanceCalcs/ChebyshevDistance.h"
#include "KNN/DistanceCalcs/EuclideanDistance.h"
#include "KNN/DistanceCalcs/ManhattanDistance.h"
#include "KNN/DistanceCalcs/DistanceCalculator.h"
#include "KNN/KNNFileClassifier.h"

ClassifyData::ClassifyData(DefaultIO &io) : Command(io, "classify data") {}

bool ClassifyData::execute(ClientData &cd) {
    //use the knn algorithm
    if(cd.getTestFile() == "<empty>" || cd.getTrainFile() == "<empty>") {
        defaultIO.send("<# Please upload CSV files first.\n>[screen_print]");
        return true;
    }
    if(cd.getClassifiesFile() == "<empty>") {   //avoid recalculation.

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
        std::string stringClassified = Flower::toFileFormat(classified);
        cd.setClassifiesFile(stringClassified);
    }
    defaultIO.send("<# Classifying data Complete!\n>[screen_print]");
    return true;
}