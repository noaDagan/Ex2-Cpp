#include "ClientHandler.h"
#include "CacheManager.h"
#include "Solver.h"
#include <string.h>
#include <string>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>


#ifndef PROJECTNUM2_MYCLIENTHANDLER_H
#define PROJECTNUM2_MYCLIENTHANDLER_H

using namespace std;

class MyClientHandler : public ClientHandler {
    Solver<string, string> *solver;
    CacheManager<string, string> *cacheManager;
public:
    MyClientHandler(Solver<string, string> *solve,
                    CacheManager<string, string> *cacheManager);

    virtual void handleCLient(int socketFd);

};


#endif //PROJECTNUM2_MYCLIENTHANDLER_H
