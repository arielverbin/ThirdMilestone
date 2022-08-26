#include "UploadFiles.h";
using namespace std;

void UploadFiles::execute() {
    defaultIO.send("Please upload your local train CSV file");

    //////// tell the client what to do

    string file = defaultIO.receive();

    ///////save the file in clientData

    defaultIO.send("Upload complete");

};