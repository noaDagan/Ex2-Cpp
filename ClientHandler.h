#include <iostream>
#include <istream>
#include <ostream>


#ifndef PROJECTNUM2_CLIENHANDLER_H
#define PROJECTNUM2_CLIENHANDLER_H

using namespace std;
class ClientHandler  {
public:
    virtual void handleCLient(int socketFd)=0;

};



#endif //PROJECTNUM2_CLIENHANDLER_H
