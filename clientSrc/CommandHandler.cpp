

#include "CommandHandler.h"
CommandHandler::CommandHandler(DefaultIO &defaultIo) : serverIO(defaultIo), screenIO(){}

void CommandHandler::handle() {
    screenIO.send(serverIO.receive()); //infinite loop....
}