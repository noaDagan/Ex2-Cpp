#include "FileCacheManager.h"

template <>
void FileCacheManager<string,string>::readFile() {
    string line;
    string problem,solution;
    ifstream problemsFile("solutionFile.txt");
    if (problemsFile.is_open()) {
        while (getline(problemsFile,line)){
            char * temp= const_cast<char*>(line.c_str());
            temp = strtok(temp, ";");
            problem=temp;
            temp=strtok(NULL, ";");
            solution=temp;
            this->solutionMap.insert(pair<string,string>(problem,solution));
        }
        problemsFile.close();
    }
}

template <>
FileCacheManager<string,string>::FileCacheManager() {
    this->readFile();
}

template <>
FileCacheManager<string,string>::~FileCacheManager() {
    ofstream problemsFile("solutionFile.txt",ios::trunc);
    if (problemsFile.is_open()) {
        map<string, string> ::iterator iter;
        for (iter = this->solutionMap.begin(); iter != this->solutionMap.end(); iter++) {
            problemsFile << (*iter).first;
            problemsFile << ";";
            problemsFile << (*iter).second;
            problemsFile << "\n";
        }
    }
}

template <>
string FileCacheManager<string,string>::getSolution(string problem) {
    return this->solutionMap.find(problem)->second;
}

template <>
void FileCacheManager<string,string>::saveSolution(string problem, string solution) {
    this->solutionMap.insert(pair<string,string> (problem, solution));
}

template <>
bool FileCacheManager <string,string>::haveSolution(string problem) {
    if (this->solutionMap.count(problem)) {
        return true;
    }
    return false;
}

