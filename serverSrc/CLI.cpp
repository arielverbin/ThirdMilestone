
#include "CLI.h"

CLI::CLI(DefaultIO& io) : io(io) {
    commands.emplace_back(new UploadFiles(io));
    commands.emplace_back(new SetParameters(io));
    commands.emplace_back(new ClassifyData(io));
    commands.emplace_back(new PrintClassifiedData(io));
    commands.emplace_back(new SaveClassifiedData(io));
    commands.emplace_back(new GetMatrix(io));
}

std::string CLI::getMenu() const{
    std::string menu = "Welcome to the KNN Classifier Server. Please choose an option:\n";
    for(int i = 0; i < commands.size(); i ++) {
        menu.append(std::to_string(i)+". "+commands[i]->getDescription()+"\n");
    }
    return menu;
}

void CLI::start() const {
    io.send("<"+ this->getMenu()+">"+"[screen_print][screen_read]");
    //infinite loop of receiving client input - i (number 1-7) and executing the command[i].
}
