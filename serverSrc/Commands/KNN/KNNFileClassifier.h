
#ifndef ADVANCEDPROGRAMMING_KNNFILECLASSIFIER_H
#define ADVANCEDPROGRAMMING_KNNFILECLASSIFIER_H

#include <string>
#include "Flowers/Flower.h"
#include "DistanceCalcs/DistanceCalculator.h"
#include "KNNClassifier.h"
/**
 * This class classifies a file of unclassified points and saves the output file in the given path.
 */
class KNNFileClassifier {
public:

    explicit KNNFileClassifier() = default;



    /**
     * Classify all unclassified points in the given file.
     * @param k the constant from the algorithm.
     * @param pathToUnclassified the path to the unclassified points file.
     * @param pathToOutputFolder the path to where the output files will be created.
     */
    std::vector<Flower> classify(int k, const std::vector<Point> &unclassified, 
                                    const std::vector<Flower> &classified, DistanceCalculator *dc) const;

private:
    /**
     * Path to the classified points.
     */
    std::string pathToClassified;

    // /**
    // * @brief get the classified points as vector of flowers from a given file.
    // * @param fileName the given file.
    // * @return the vector of flowers.
    // */
    // static std::vector <Flower> getDataFromFile(const std::string &fileName) ;

    /**
     * classify all of the points according to the given classifier, distance calculator, and k.
     * @param dc the distance calculator.
     * @param knn the classifier.
     * @param unclassifiedPoints the points to be classified.
     * @param k the constant k from the algorithm.
     * @return new vector of classified points (as flowers).
     */
    static std::vector <Flower> classifyAll(DistanceCalculator &dc, KNNClassifier &knn,
                                     const std::vector<Point> &unclassifiedPoints, int k) ;

};


#endif //ADVANCEDPROGRAMMING_KNNFILECLASSIFIER_H
