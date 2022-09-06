#include "Point.h"
#include "Flowers/Flower.h"
#include "KNNClassifier.h"
#include "DistanceCalcs/DistanceCalculator.h"
#include <vector>
#include "KNNVectorClassifier.h"

using namespace std;

KNNVectorClassifier::KNNVectorClassifier(const int k, std::vector<Flower> classified) :
                                            k(k), knnClassifier(std::move(classified)){}

std::vector<Flower> KNNVectorClassifier::classifyAll(DistanceCalculator &dc,
                                                   const std::vector<Point> &unclassifiedPoints, int newK) {
    std::vector<Flower> classifiedPoints; //to be filled with the classified points.

    for (auto &curPoint: unclassifiedPoints) {
        //take the current point.
        classifiedPoints.emplace_back(Flower(curPoint, //classify it and create a new flower.
                                             knnClassifier.classify(curPoint, newK, dc)));

        if(classifiedPoints[classifiedPoints.size() - 1].getType() == "<Error in classifying.>")
            return std::vector<Flower>{Flower(Point(std::vector<double>{0}),"<error>")};
    }
    return classifiedPoints;
}

std::vector<Flower> KNNVectorClassifier::classify(const std::vector<Point> &unclassifiedPoints, DistanceCalculator *dc) {
    if(unclassifiedPoints.size() < k)
        return classifyAll(*dc, unclassifiedPoints, (int)unclassifiedPoints.size());
    else return classifyAll(*dc, unclassifiedPoints, k);
}