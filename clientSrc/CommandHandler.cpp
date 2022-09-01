

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

void CommandHandler::handle() {
    while(true) {
        std::string rawMessage = serverIO.receive();
        if(rawMessage == "<closed>") return; //Server closed.
        std::stack<std::string> instructions = analyzeInstructions(rawMessage);
        std::string curInstruction;

        while (!instructions.empty()) {
            curInstruction = instructions.top();
            if (curInstruction[0] == '<') {
                buffer = curInstruction.substr(1, curInstruction.size() - 2); continue;
            }
            if (curInstruction == "[screen_print]") {
                screenIO.send(buffer); continue;
            }
            if (curInstruction == "[screen_read]") {
                buffer = screenIO.receive(); continue;
            }
            if (curInstruction == "[file_input]") {
                FileIO fileIo(screenIO.receive()); //get path.
                buffer = fileIo.receive();
                if(buffer == "<error>") {screenIO.send("[!] Error: could not read from file."); break;}
                continue;
            }
            if(curInstruction == "[file_output]") {
                FileIO fileIo(screenIO.receive()); //get path.
                if(!fileIo.send(buffer)) {screenIO.send("[!] Error: could not send to file."); break;}
                continue;
            }
            if (curInstruction == "[send_back]") {
                serverIO.send(buffer); continue;
            }
            screenIO.send("[!] Server sent: " + curInstruction +", which is not a recognized instruction.");
        }
    }
}