#include "SetParameters.h";
#include <vector>
#include <sstream>

using namespace std;

SetParameters::SetParameters(DefaultIO &io) : Command(io, "algorithm settings") {}

void SetParameters::execute(ClientData cd) {
      //give the client instructions   
    defaultIO.send("<The current KNN parameters are: K = " + std::to_string(cd.getK()) + 
    ", distance metric = " + cd.getDistanceMetric()+">[screen_print][screen_read][send_back]");
    
    //get input fron the user

    while(true){
        string input = defaultIO.receive();
        string enter;
        enter.push_back('\n');
        if (!input.compare(enter)){
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
            if (newK >= 1 && newK <= 10){
                if (newMatric.compare("CHE") || newMatric.compare("MAN") || newMatric.compare("EUC")){
                    cd.setK(newK);
                    cd.setDistanceMetric(newMatric);
                    break;
                }
                else{
                    defaultIO.send("<Invalid value for K>[screen_print][screen_read][send_back]");
                }
            }
            else{
                defaultIO.send("<Invalid value for distance matric>[screen_print][screen_read][send_back]");
            }
        }
    }
};