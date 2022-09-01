
#include "CLI.h"

CLI::CLI(DefaultIO &io, ClientData &cd) : io(io), clientData(cd) {
    commands.emplace_back(new UploadFiles(io));
    commands.emplace_back(new SetParameters(io));
    commands.emplace_back(new ClassifyData(io));
    commands.emplace_back(new PrintClassifiedData(io));
    commands.emplace_back(new SaveClassifiedData(io));
    commands.emplace_back(new GetMatrix(io));
}

std::string CLI::getMenu() const {
    std::string menu = "Welcome to the KNN Classifier Server. Please choose an option:\n";
    for (int i = 0; i < commands.size(); i++) {
        menu.append(std::to_string(i + 1) + ". " + commands[i]->getDescription() + "\n");
    }
    menu.append(std::to_string(commands.size() + 1) + ". exit");
    return menu;
}

void CLI::start() const {
    io.send("<" + this->getMenu() + ">" + "[screen_print][screen_read][send_back]");
    std::string raw = io.receive();
    if (raw == "<error>") return;

    int commandRequest = std::stoi(raw);

    while (commandRequest != commands.size() + 1) {
        if (!commands[commandRequest - 1]->execute(clientData))
            return; //some error occurred while executing.

        io.send("<" + this->getMenu() + ">" + "[screen_print][screen_read][send_back]");
        raw = io.receive();
        if (raw == "<error>") return;
        commandRequest = std::stoi(raw);
    }
}
CLI::~CLI() {
    for(Command* c : commands) {
        delete c;
    }
}
