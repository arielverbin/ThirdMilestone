#include "PrintClassifiedData.h"

using namespace std;

PrintClassifiedData::PrintClassifiedData(DefaultIO &io) : Command(io, "display results") {}

void PrintClassifiedData::execute(ClientData cd) {

    defaultIO.send("<" + cd.getClassifies() + ">[screen_print]");
       
    defaultIO.send("<Done.>[screen_print]");
        
};