#ifndef THIRDMILESTONE_SERVERSRC_COMMANDS_CLASSIFYDATA_H
#define THIRDMILESTONE_SERVERSRC_COMMANDS_CLASSIFYDATA_H

#include "Command.h"
#include <iostream>
#include <fstream>
#include "../KNN/Point.hpp"
#include "../KNN/Flowers/Flower.hpp"
#include "../KNN/KNNClassifier.hpp"
#include "../KNN/DistanceCalcs/ChebyshevDistance.hpp"
#include "../KNN/DistanceCalcs/EuclideanDistance.hpp"
#include "../KNN/DistanceCalcs/ManhattanDistance.hpp"
#include "../KNN/DistanceCalcs/DistanceCalculator.hpp"
#include "../KNN/KNNFileClassifier.hpp"








/**
 * @brief command 3 - classify the data.
 * 
 */
class ClassifyData : public Command {
public:
    explicit ClassifyData(DefaultIO &io);

    void execute(ClientData cd) override;
};

#endif //THIRDMILESTONE_SERVERSRC_COMMANDS_CLASSIFYDATA_H