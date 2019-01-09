#include "ClientHandler.h"

#ifndef PROJECTNUM2_SERVER_H
#define PROJECTNUM2_SERVER_H

namespace server_side {

    class Server {
    public:

        virtual void open(int port, ClientHandler *clientHandler) = 0;

        virtual void stop(int socketFd) = 0;

    };
}

#endif //PROJECTNUM2_SERVER_H
