#include "SaveClassifiedData.h"

using namespace std;

SaveClassifiedData::SaveClassifiedData(DefaultIO &io) : Command(io, "download results") {}

void SaveClassifiedData::execute(ClientData cd) {

    defaultIO.send("<"+ cd.getClassifies() +"><results.txt>[file_output]");
                
}