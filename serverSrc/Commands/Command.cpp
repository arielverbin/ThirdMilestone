#include "Command.h"

Command::Command(DefaultIO &io, std::string description) : defaultIO(io), description(std::move(description)) {}

std::string Command::getDescription() {
    return description;
}