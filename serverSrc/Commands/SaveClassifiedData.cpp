#include "SaveClassifiedData.h"

using namespace std;

SaveClassifiedData::SaveClassifiedData(DefaultIO &io) : Command(io, "download results") {}

bool SaveClassifiedData::execute(ClientData& cd) {
    if(cd.getClassifiesFile() == "<empty>"){
        defaultIO.send("<# Please upload CSV files first.\n>[screen_print]");
        return true;
    }
    defaultIO.send("<# Enter a path to the output file location...>[screen_print]<"+
                                                cd.getClassifiesFile() +">[file_output]<results.txt>");
    return true;
}