
#ifndef ADVANCEDPROGRAMMING_DISTANCECALCULATOR_H
#define ADVANCEDPROGRAMMING_DISTANCECALCULATOR_H

#include "../Point.h"
/**
 * A DistanceCalculator can calculate the distance between 2 Points, using an virtual formula.
 * It can also return the K-nearest points from a given point out of an array of data.
 */
class DistanceCalculator {
public:
    virtual double calculate(const Point &p1, const Point &p2) = 0;
    virtual ~DistanceCalculator() = default;
};


#endif //ADVANCEDPROGRAMMING_DISTANCECALCULATOR_H
