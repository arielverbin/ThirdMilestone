#include "UploadFiles.h"
#include <utility>

using namespace std;

UploadFiles::UploadFiles(DefaultIO &io) : Command(io, "upload an unclassified csv data file") {}

bool UploadFiles::execute(ClientData& cd) {
    //give the client instructions
    defaultIO.send("<Please upload your local train CSV file>[screen_print][file_input][send_back]");

    string trainFile = defaultIO.receive();
    if(trainFile == "<error>") return false;
    defaultIO.send("<# Upload Complete!\n>[screen_print]");

    //give the client instructions
    defaultIO.send("<Please upload your local test CSV file>[screen_print][file_input][send_back]");

    string testFile = defaultIO.receive();
    if(testFile == "<error>") return false;
    defaultIO.send("<# Upload Complete!\n>[screen_print]");

    //save the files
    save(cd, testFile, trainFile);
    return true;
}

void UploadFiles::save(ClientData& cd, std::string& testFile, std::string& trainFile) {
    cd.setTestFile(std::move(testFile));
    cd.setTrainFile(std::move(trainFile));
    //reset relevant data:
    cd.setConfusionMatrix(nullptr);
    cd.setClassifiesFile("<empty>");
}