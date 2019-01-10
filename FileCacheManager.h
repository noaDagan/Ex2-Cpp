#include "CacheManager.h"
#include <map>
#include <fstream>
#include <iostream>
#include <string.h>

#ifndef PROJECTNUM2_FILECACHEMANAGER_H
#define PROJECTNUM2_FILECACHEMANAGER_H

template<class T1, class T2>

class FileCacheManager : public CacheManager<string, string> {
    map <string, string> solutionMap;
public:
    void readFile() {
        string line;
        string problem, solution;
        ifstream problemsFile("/home/noa/Desktop/C++/projectNum2/solutionFile.txt");
        if (problemsFile.is_open()) {
            while (getline(problemsFile, line)) {
                char *temp = const_cast<char *>(line.c_str());
                temp = strtok(temp, ";");
                problem = temp;
                temp = strtok(NULL, ";");
                solution = temp;
                this->solutionMap.insert(
                        pair<string, string>(problem, solution));
            }
            problemsFile.close();
        }
    }

    FileCacheManager() {
        this->readFile();
    }


    ~FileCacheManager() {
        ofstream problemsFile("/home/noa/Desktop/C++/projectNum2/solutionFile.txt", ios::trunc);
        if (problemsFile.is_open()) {
            map<string, string>::iterator iter;
            for (iter = this->solutionMap.begin();
                 iter != this->solutionMap.end(); iter++) {
                problemsFile << (*iter).first;
                problemsFile << ";";
                problemsFile << (*iter).second;
                problemsFile << "\n";
            }
        }
    }


    string getSolution(string problem) {
        return this->solutionMap.find(problem)->second;
    }

    void saveSolution(string problem, string solution) {
        this->solutionMap.insert(pair<string, string>(problem, solution));
    }

    bool haveSolution(string problem) {
        if (this->solutionMap.count(problem)) {
            return true;
        }
        return false;
    }
};


#endif //PROJECTNUM2_FILECACHEMANAGER_H
