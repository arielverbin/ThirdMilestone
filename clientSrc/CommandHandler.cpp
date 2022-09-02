

#include "CommandHandler.h"

CommandHandler::CommandHandler(DefaultIO &defaultIo) : serverIO(defaultIo), screenIO() {}

std::stack<std::string> CommandHandler::analyzeInstructions(std::string& raw) {
    std::stack<std::string> flipped;
    int current = 0, length;
    while (current < raw.size()) {
        length = 1;
        if (raw[current] == '<') {
            while (raw[length + current] != '>') length++;
        } else if (raw[current] == '[') {
            while (raw[length + current] != ']') length++;
        } else break; //invalid format, returns the valid prefix of the string.
        flipped.push(raw.substr(current, length + 1));
        current += (length + 1);
    }
    std::stack<std::string> res;
    while (!flipped.empty()) {
        res.push(flipped.top());
        flipped.pop();
    }
    return res;
}

void* CommandHandler::saveFile(void *args) {
    char* got = (char*) args;
    std::string input(got);
    size_t sep = input.find('$');
    FileIO fileIo(input.substr(0, sep)); //get path.
    if(!fileIo.send(input.substr(sep + 1))){
        std::cout << "[!] Error: could not send to file." << std::endl;
    }
    delete got;
    return nullptr;
}

void CommandHandler::handle() {
    while(true) {
        std::string rawMessage = serverIO.receive();
        if(rawMessage == "<error>") return; //Server closed.
        std::stack<std::string> instructions = analyzeInstructions(rawMessage);
        std::string curInstruction;

        while (!instructions.empty()) {
            curInstruction = instructions.top();
            instructions.pop();
            if (curInstruction[0] == '<') {
                buffer = curInstruction.substr(1, curInstruction.size() - 2); continue;
            }
            if (curInstruction == "[screen_print]") {
                screenIO.send(buffer + "\n"); continue;
            }
            if (curInstruction == "[screen_read]") {
                screenIO.send(">>>> ");
                buffer = screenIO.receive(); continue;
            }
            if (curInstruction == "[file_input]") {
                screenIO.send(">>>> ");
                FileIO fileIo(screenIO.receive()); //get path.
                buffer = fileIo.receive();
                if(buffer == "<error>") {screenIO.send("[!] Error: could not read from file.\n"); return;}
                continue;
            }
            if(curInstruction == "[file_output]") {
                pthread_t id;
                std::string fileName = instructions.top(); instructions.pop();
                fileName = fileName.substr(1, fileName.size() - 2); //"<file>" --TO--> "file"

                screenIO.send(">>>> ");
                std::string path = screenIO.receive() + "/" + fileName; //get path.
                std::string str = path + "$" + buffer; //connect path to context of file.

                char* toSend = new char[str.size() + 1];
                str.copy(toSend, str.size(), 0); toSend[str.size()] = '\0';

                pthread_create(&id, nullptr, saveFile, toSend);
                continue;
            }
            if (curInstruction == "[send_back]") {
                serverIO.send(buffer); continue;
            }
            screenIO.send("[!] Server sent: " + curInstruction +", which is not a recognized instruction.\n");
        }
    }
}