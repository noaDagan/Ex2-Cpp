
#include "Solver.h"
#include <string>
#include "Matrix.h"
#include "Searcher.h"
#include "Searchable.h"

#ifndef PROJECTNUM2_MATRIXSOLVER_H
#define PROJECTNUM2_MATRIXSOLVER_H
using namespace std;

template<class PROBLEM, class SOLUTION>
class MatrixSolver : public Solver<PROBLEM, SOLUTION> {
    Searcher<PROBLEM> *searcher;
public:

    MatrixSolver(Searcher<PROBLEM> *s) {
        this->searcher = s;
    }

     string solve(string problem) {
        Searchable<string> *matrix = this->createMatrix(problem);
        return this->searcher->search(matrix);

    }

    Matrix<string> * createMatrix(string values) {
        Matrix<string> *matrix = new Matrix<string>();
        char *temp = const_cast<char *>(values.c_str());
        char* temp2 = strtok(temp, ";");
        list<string> stringList;
        while (temp2!=NULL){
            stringList.push_back(string(temp2));
            temp2 = strtok(NULL, ";");
        }
        list<string>::iterator iter;
        iter=stringList.begin();
        while (*iter != "end") {
            string s = *iter;
            matrix->addRow(s);
            ++iter;
        }
        //temp2 = strtok(temp2, ";");
        iter++;
        string initializeState = *iter;
        char *index = const_cast<char *>(initializeState.c_str());
        index = strtok(index, ",");
        int i = stoi(index);
        index = strtok(NULL, ",");
        int j = stoi(index);
        matrix->setInitialState(matrix->getStateByIndex(i, j));
        iter++;
        initializeState = *iter;
        index = const_cast<char *>(initializeState.c_str());
        index = strtok(index, ",");
        i = stoi(index);
        index = strtok(NULL, ",");
        j = stoi(index);
        matrix->setGoalState(matrix->getStateByIndex(i, j));
        return matrix;
    }


};


#endif //PROJECTNUM2_MATRIXSOLVER_H
