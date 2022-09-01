
#ifndef THIRDMILESTONE_TIMEOUT_H
#define THIRDMILESTONE_TIMEOUT_H

#include "../IO/SocketIO.h"
#include <netinet/in.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include <iostream>
#include <arpa/inet.h>
#include <chrono>

class Timeout {
private:
    const int seconds;
    const int serverPort;
    bool* timeoutPassed;
public:
    Timeout(int seconds, int serverPort, bool* timeoutPassed);
    void count();

};


#endif //THIRDMILESTONE_TIMEOUT_H
