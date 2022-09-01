#include "PrintClassifiedData.h"

using namespace std;

PrintClassifiedData::PrintClassifiedData(DefaultIO &io) : Command(io, "display results") {}

bool PrintClassifiedData::execute(ClientData &cd) {
    if(cd.getClassifiesFile() == "<empty>") {
        defaultIO.send("<# Please Classify First.\n>[screen_print]");
        return true;
    }
    defaultIO.send("<" + cd.getClassifiesFile() + ">[screen_print]");

    defaultIO.send("<# Done.>[screen_print]");
    return true;
}