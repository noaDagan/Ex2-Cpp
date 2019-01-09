#include <iostream>
#include <thread>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/socket.h>
#include <functional>
#include "Server.h"
#include "ClientHandler.h"
#include <time.h>

#ifndef PROJECTNUM2_MYSERIALSERVER_H
#define PROJECTNUM2_MYSERIALSERVER_H

using namespace server_side;

class MySerialServer : public Server  {
public:
    MySerialServer();

    void open(int port, ClientHandler *clientHandler);

    void stop(int socketFd);
};


#endif //PROJECTNUM2_MYSERIALSERVER_H
