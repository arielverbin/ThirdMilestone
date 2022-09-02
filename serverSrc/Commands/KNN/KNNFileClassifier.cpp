#include "Point.h"
#include "Flowers/Flower.h"
#include "KNNClassifier.h"
#include "DistanceCalcs/DistanceCalculator.h"
#include <vector>
#include "KNNFileClassifier.h"

using namespace std;

std::vector<Flower> KNNFileClassifier::classifyAll(DistanceCalculator &dc, KNNClassifier &knn,
                                                   const std::vector<Point> &unclassifiedPoints, int k) {
    std::vector<Flower> classifiedPoints; //to be filled with the classified points.

    for (auto &curPoint: unclassifiedPoints) {
        //take the current point.
        classifiedPoints.emplace_back(Flower(curPoint, //classify it and create a new flower.
                                             knn.classify(curPoint, k, dc)));

        if(classifiedPoints[classifiedPoints.size() - 1].getType() == "<Error in classifying.>")
            return std::vector<Flower>{Flower(Point(std::vector<double>{0}),"<error>")};
    }
    return classifiedPoints;
}

/**
 * main method.
 */
std::vector<Flower> KNNFileClassifier::classify(int k, const std::vector<Point> &unclassifiedPoints,
                                            const std::vector<Flower> &classifiedPoints, DistanceCalculator *dc) const {
    // std::vector<Flower> flowers = getDataFromFile(this->pathToClassified); //fill "flowers" with classifieds.

    KNNClassifier knnClassifier = KNNClassifier(classifiedPoints); //new KNNClassifier.

    return classifyAll(*dc,knnClassifier, unclassifiedPoints, k);

}