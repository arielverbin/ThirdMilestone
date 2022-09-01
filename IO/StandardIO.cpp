
#include "StandardIO.h"

bool StandardIO::send(std::string message) {
    std::cout << message;
    return true;
}
std::string StandardIO::receive() {
    std::string message;
    std::getline(std::cin, message);
    return std::move(message);
}
