#include "UploadFiles.h"
#include <utility>

using namespace std;

UploadFiles::UploadFiles(DefaultIO &io) : Command(io, "upload an unclassified csv data file") {}

void UploadFiles::execute(ClientData cd) {
    //give the client instructions
    defaultIO.send("<Please upload your local train CSV file>[screen_print][screen_read][file_input]");

    string trainFile = defaultIO.receive();
    defaultIO.send("Upload complete");

    //give the client instructions
    defaultIO.send("<Please upload your local test CSV file>[screen_print][screen_read][file_input]");

    string testFile = defaultIO.receive();
    defaultIO.send("Upload complete[screen_print]");
    
    //save the files
    save(cd, testFile, trainFile);
};

void UploadFiles::save(ClientData cd, std::string testFile, std::string trainFile) {
    cd.setTestFile(std::move(testFile));
    cd.setTrainFile(std::move(trainFile));

}
