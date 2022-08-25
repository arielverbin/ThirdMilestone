
#ifndef THIRDMILESTONE_DEFAULTIO_H
#define THIRDMILESTONE_DEFAULTIO_H

#include <string>
class DefaultIO {
public:
    /**
    * receives a message from the socket.
    * @return the message, of <error> if error occurred.
    */
    virtual std::string receive() = 0;
    /**
     * Send a message through the socket.
     * @param message the message as string.
     * NOTE: the length of the message is not bounded, cant have the char '$' (reserved).
     * @return true if it was successful, false otherwise.
     */
    virtual bool send(std::string message) = 0;
};


#endif //THIRDMILESTONE_DEFAULTIO_H
