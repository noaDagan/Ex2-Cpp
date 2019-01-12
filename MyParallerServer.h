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

#ifndef PROJECTNUM2_MYPARALLERSERVER_H
#define PROJECTNUM2_MYPARALLERSERVER_H
using namespace server_side;

class MyParallerServer : public Server {
public:
    //Constructor
    MyParallerServer();

    /**
     * The function open a server that listem to multiple clients simultaneously
     */
    void open(int port, ClientHandler *clientHandler);

    /**
     * The function stop the server
     */
    void stop(int socketFd);

};


#endif //PROJECTNUM2_MYPARALLERSERVER_H
