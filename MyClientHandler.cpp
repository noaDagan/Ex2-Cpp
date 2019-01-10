
#include "MyClientHandler.h"

MyClientHandler::MyClientHandler(Solver<string, string> *solve,
                                 CacheManager<string, string> *cacheManager) {
    this->solver = solve;
    this->cacheManager = cacheManager;
}

void MyClientHandler::handleCLient(int socketFd) {
    char buffer[1025];
    int n;
    string result = "";
    string problem = "";
  //  while (true) {
        bzero(buffer, 1025);
        n = read(socketFd, buffer, 1024);
        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }
        while (strcmp(buffer, "end") != 0) {
            string temp = string(buffer);
            problem += temp + ";";
            cout << "problem :" + problem<<endl;
            bzero(buffer, 1025);
            n = read(socketFd, buffer, 1024);
            if (n < 0) {
                perror("ERROR reading from socket");
                exit(1);
            }
        }
        problem += "end;";
        bzero(buffer, 1025);
        n = read(socketFd, buffer, 1024);
        problem += string(buffer) + ";";
        bzero(buffer, 1025);

        n = read(socketFd, buffer, 1024);
        problem += string(buffer);
        cout << "problem :" + problem<<endl;

        if (this->cacheManager->haveSolution(problem)) {
            result = this->cacheManager->getSolution(problem);
        } else {
            result = this->solver->solve(problem);
            this->cacheManager->saveSolution(problem, result);
        }
        char* bufferWrite = const_cast<char*>(result.c_str());
        cout << "result :" + result<<endl;

        n = write(socketFd, bufferWrite, 1024);
        close(socketFd);
   // }
}