#include "PrintClassifiedData.h"

using namespace std;

PrintClassifiedData::PrintClassifiedData(DefaultIO &io) : Command(io, "display results") {}

void PrintClassifiedData::execute(ClientData cd) {

    int i = 1;
    ifstream file(cd.getTestFile());
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            defaultIO.send("<"+to_string(i) + "     " + line+">" + "[screen_print]");
        }
        defaultIO.send("<Done.>[screen_print]");
        file.close();
    }
};