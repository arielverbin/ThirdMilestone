
#include "Timeout.h"

Timeout::Timeout(const int seconds, const int serverPort) : seconds(seconds), serverPort(serverPort){}

void Timeout::count() {
    auto start = std::chrono::steady_clock::now();

    sleep(seconds);
    //cancel accept with creating a connection.
    const char *ip_address = "127.0.0.1"; //connection between the device to itself;
    int socket = ::socket(AF_INET, SOCK_STREAM, 0);

    if (socket < 0) { perror("[Timeout] Could not connect to server. Timeout is disabled.");
        return;
    }
    struct sockaddr_in sin{};
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = inet_addr(ip_address);
    sin.sin_port = htons(serverPort);

    if (connect(socket, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("[Timeout] Could not connect to server. Timeout is disabled."); return;
    }
    SocketIO socketIo(socket);
    socketIo.send("<timeout>");
    close(socket);
}