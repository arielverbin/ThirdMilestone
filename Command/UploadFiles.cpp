#include "UploadFiles.h";
using namespace std;

UploadFiles::UploadFiles(){
    description = "upload an unclassfied csv data file";
}

void UploadFiles::execute(clientData cd) {

    defaultIO.send("Please upload your local train CSV file<");

    //////// tell the client what to do

    string trainFile = defaultIO.receive();
    defaultIO.send("Upload complete");


    defaultIO.send("Please upload your local test CSV file");

    //////// tell the client what to do

    string testFile = defaultIO.receive();
    defaultIO.send("Upload complete");

    save(cd, testFile, trainFile);
};

void UploadFiles::save(clientData cd, string testFile, string trainFile) {
    cd.setTestFile(testFile);
    cd.setTrainFile(trainFile);

};