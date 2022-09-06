
#ifndef ADVANCEDPROGRAMMING_KNNFILECLASSIFIER_H
#define ADVANCEDPROGRAMMING_KNNFILECLASSIFIER_H

#include <string>
#include "Flowers/Flower.h"
#include "DistanceCalcs/DistanceCalculator.h"
#include "KNNClassifier.h"
/**
 * This class classifies a file of unclassified points and saves the output file in the given path.
 */
class KNNVectorClassifier {
public:
    /**
     * Constructor.
     * @param k from the algorithm.
     * @param classified list of database (classified points).
     */
    explicit KNNVectorClassifier(int k, std::vector<Flower> classified);

    /**
      * Classify a whole vector of unclassified points.
      * @param unclassified the unclassified points.
      * @param dc the metric method.
      * @return a vector of classified points.
      */
    std::vector<Flower> classify(const std::vector<Point> &unclassified, DistanceCalculator *dc);

private:
    //k of algorithm.
    const int k;
    //delegation.
    KNNClassifier knnClassifier;
    /**
     * classify all of the points according to the given classifier, distance calculator, and k.
     * @param dc the distance calculator.
     * @param unclassifiedPoints the points to be classified.
     * @param k from the algorithm.
     * @return new vector of classified points (as flowers).
     */
    std::vector <Flower> classifyAll(DistanceCalculator &dc,
                                     const std::vector<Point> &unclassifiedPoints, int k) ;

};


#endif //ADVANCEDPROGRAMMING_KNNFILECLASSIFIER_H
