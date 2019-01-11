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

    /**
     * The function read the solution fike and save the information in a map
     */
    void readFile() {
        string line;
        string problem, solution;
        //Open the file
        ifstream problemsFile("/home/noa/Desktop/C++/projectNum2/solutionFile.txt");
        if (problemsFile.is_open()) {
            //While it is not the end of the file
            while (getline(problemsFile, line)) {
                //Split the line for problem and solution
                char *temp = const_cast<char *>(line.c_str());
                temp = strtok(temp, ";");
                problem = temp;
                temp = strtok(NULL, ";");
                solution = temp;
                //Add it to the map.
                this->solutionMap.insert(
                        pair<string, string>(problem, solution));
            }
            problemsFile.close();
        }
    }

    //Constructor
    FileCacheManager() {
        this->readFile();
    }


    //Distructor
    ~FileCacheManager() {
        //Save the map to the solution file
        ofstream problemsFile("/home/noa/Desktop/C++/projectNum2/solutionFile.txt", ios::trunc);
        if (problemsFile.is_open()) {
            //Go ovet the map and write the information to the file
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


    /**
     * The function returns returns a saved solution to a given problem.
     */
    string getSolution(string problem) {
        return this->solutionMap.find(problem)->second;
    }


    **
    * Thr function receive a problem and solution and save them.
    */
    void saveSolution(string problem, string solution) {
        this->solutionMap.insert(pair<string, string>(problem, solution));
    }


    /**
     * The function returns if the solution to a given problem  was already solved and saved.
     */
    bool haveSolution(string problem) {
        if (this->solutionMap.count(problem)) {
            return true;
        }
        return false;
    }
};


#endif //PROJECTNUM2_FILECACHEMANAGER_H
