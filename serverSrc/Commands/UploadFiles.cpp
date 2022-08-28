#include "UploadFiles.h"

#include <utility>

UploadFiles::UploadFiles(DefaultIO &io) : Command(io, "upload an unclassified csv data file") {}

void UploadFiles::execute(ClientData cd) {

    defaultIO.send("Please upload your local train CSV file<");

    //////// tell the client what to do

    std::string trainFile = defaultIO.receive();
    defaultIO.send("Upload complete");

    defaultIO.send("Please upload your local test CSV file");

    //////// tell the client what to do

    std::string testFile = defaultIO.receive();
    defaultIO.send("Upload complete");

    save(cd, testFile, trainFile);
}

void UploadFiles::save(ClientData cd, std::string testFile, std::string trainFile) {
    cd.setTestFile(std::move(testFile));
    cd.setTrainFile(std::move(trainFile));

}
