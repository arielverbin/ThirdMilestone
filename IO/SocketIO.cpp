
#include "SocketIO.h"
const int SocketIO::bufferSize = 128;

SocketIO::SocketIO(int socket) : socket(socket){}

bool SocketIO::send(std::string message) {
    int index = 0;
    std::string curMessage; char buffer[SocketIO::bufferSize];

    while (index + SocketIO::bufferSize - 1 <= message.size()) { //send in pieces of 128 bytes.
        curMessage = message.substr(index, SocketIO::bufferSize - 1);
        curMessage.copy(buffer, sizeof(buffer)); buffer[sizeof(buffer)-1] = '\0'; //copy current message to buffer.

        index += SocketIO::bufferSize - 1;
        int sent_bytes = (int) ::send(socket, buffer, sizeof(buffer), 0);

        if (sent_bytes < 0) { std::cout << "Error in sending bytes" << std::endl; return false; }
    }
    //rest of message (will be smaller than 128 bytes):
    curMessage = message.substr(index) + "$";
    curMessage.copy(buffer, sizeof(buffer)); buffer[curMessage.size()] = '\0';
    int sent_bytes = (int) ::send(socket, buffer, sizeof(buffer), 0);

    if (sent_bytes < 0) { std::cout << "Error in sending bytes" << std::endl; return false; }

    return true;
}

std::string SocketIO::receive() {
    std::string rawMessage;
    char buffer[SocketIO::bufferSize+1];

    while (rawMessage.find('$') == std::string::npos) {
        int read_bytes = (int) ::recv(socket, buffer, sizeof(buffer)-1, 0); //receive data from client.

        if (read_bytes == 0) { return "<error>"; }
        else if (read_bytes < 0) { std::cout << "Error reading bytes." << std::endl;
            return "<error>";
        }
        buffer[SocketIO::bufferSize] = '\0';
        rawMessage.append(buffer);
    }
    rawMessage.pop_back(); //remove '$' at the end.
    return rawMessage;
}
