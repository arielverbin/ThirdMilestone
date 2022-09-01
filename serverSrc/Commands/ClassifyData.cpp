#include "ClassifyData.h"

ClassifyData::ClassifyData(DefaultIO &io) : Command(io, "classify data") {}

void ClassifyData::execute(ClientData cd) {
    //use the knn algoritem 
    std::string testFile = cd.getTestFile();
    std::string trainFile = cd.getTrainFile();

    std::vector<Point> unclassifiedPoints = Point::toPoints(testFile, '\n');
    std::vector<Flower> classifiedPoints = Flower::toFlowers(trainFile, '\n');

    DistanceCalculator* distandeMatric;
    
    if (cd.getDistanceMetric().compare("EUC")){
        auto *distandeMatric = new EuclideanDistance();
    }
    else if (cd.getDistanceMetric().compare("MAN")){
        auto *distandeMatric = new ManhattanDistance();
    }
    else {
    auto *distandeMatric = new ChebyshevDistance();
    }

    KNNFileClassifier knnFileClassifier = KNNFileClassifier();
    std::vector<Flower> classified = knnFileClassifier.classify(cd.getK(), unclassifiedPoints, classifiedPoints, distandeMatric);
    
    std::string stringClassified = Flower::toFileFormat(classified);
    cd.setClassifies(stringClassified);
    
    defaultIO.send("<classifying data complete>[screen_print]");
};