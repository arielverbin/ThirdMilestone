#include "ClassifyData.h"

ClassifyData::ClassifyData(DefaultIO &io) : Command(io, "classify data") {}

void ClassifyData::execute(ClientData cd) {
    //use the knn algoritem 

    defaultIO.send("<classifying data complete>[screen_print]");
};