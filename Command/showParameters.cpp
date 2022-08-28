#include "showParameters.h";
#include <vector>
#include <sstream>

using namespace std;

void showParameters::execute(clientData cd) {
    defaultIO.send("The current KNN parameters are: K = " + std::to_string(cd.getK()) + 
    ", distance metric = " + cd.getDestanceMetric());

    ///// need to complete the messege with information from the clientData

    //get input fron the user
    //need to tell the user what to do
    string input;
    cin >> input;
    if (!input.compare("\n")){
        //cut the input to K, matric
        std::stringstream inputHelper(input);
        std::string segment;
        std::vector<std::string> seglist;

        while(std::getline(inputHelper, segment, ' '))
        {
        seglist.push_back(segment);
        }

        int newK = stoi(seglist[0]);
        string newMatric = seglist[1];

        //check if the input is legal
        while(true){
            if (newK >= 1 && newK <= 10){
                if (newMatric.compare("CHE") || newMatric.compare("MAN") || newMatric.compare("EUC")){
                    cd.setK(newK);
                    cd.setDestanceMetric(newMatric);
                    break;
                }
                else{
                    defaultIO.send("Invalid value for K");
                }
            }
            else{
                defaultIO.send("Invalid value for distance matric");
            }
        }
    }
};