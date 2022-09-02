#include "SetParameters.h"
#include <vector>
#include <sstream>
#include <stdexcept>

using namespace std;

SetParameters::SetParameters(DefaultIO &io) : Command(io, "algorithm settings") {}

void SetParameters::reportInvalidInput(const std::string &mes) {
    defaultIO.send("<" + mes + ">" + "[screen_print][screen_read][send_back]");
}

bool SetParameters::execute(ClientData &cd) {
    // Send current parameters and ask for input.
    defaultIO.send("<# The current KNN parameters are: K = " + std::to_string(cd.getK()) +
                   ", distance metric = " + cd.getDistanceMetric() + ">[screen_print][screen_read][send_back]");

    while (true) {
        string input = defaultIO.receive(); if(input == "<error>") return false;
        if (!input.empty()) {
            size_t spaceChar = input.find(' ');
            if (spaceChar == string::npos) {
                reportInvalidInput("# Invalid format. Use \"[1-10] [CHE|MAN|EUC].\""); continue;
            }
            std::string newMetric = input.substr(spaceChar + 1); //metric method.
            int newK; //k

            try {
                newK = std::stoi(input.substr(0, spaceChar));
            } catch (const std::invalid_argument & e) {
                reportInvalidInput("# Invalid value for K (not a number)."); continue;
            }

            //check if the input is legal
            if (newK >= 1 && newK <= 10) {
                if (newMetric == "CHE" || newMetric == "MAN" || newMetric == "EUC") {
                    cd.setK(newK);
                    cd.setDistanceMetric(newMetric);
                    break;
                } else {
                    reportInvalidInput("# Invalid value for Distance Metric."); continue;
                }
            } else { reportInvalidInput("# Invalid value for K (must be in range 1-10)."); }
        } else return true; //if the user pressed enter (only).
    }
    cd.setConfusionMatrix("<empty>"); //delete previous confusion matrix.
    cd.setClassifiesFile("<empty>"); //delete previous classifieds.
    return true;
}