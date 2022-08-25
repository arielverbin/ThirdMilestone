//
// Created by Ariel Verbin on 25/08/2022.
//

#ifndef THIRDMILESTONE_SOCKETIO_H
#define THIRDMILESTONE_SOCKETIO_H

#include "DefaultIO.h"
#include <sys/socket.h>
#include <iostream>
/**
 * send a receive messages through a socket.
 */
class SocketIO : public DefaultIO{
private:
    int socket;
    /** max size of one message, does not affect functionality. **/
    static const int bufferSize;

public:
    explicit SocketIO(int socket);

    bool send(std::string message) override;

    std::string receive() override;
};


#endif //THIRDMILESTONE_SOCKETIO_H
