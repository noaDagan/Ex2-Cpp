
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

    //Constructor
    MatrixSolver(Searcher<PROBLEM> *s) {
        this->searcher = s;
    }

    /**
     * The function receive a string representing a matrix,
     * and returns a path in th matrix from the initial to the goal state.
     */
     string solve(string problem) {
         //Create the matrix with the string received
        Searchable<string> *matrix = this->createMatrix(problem);
        return this->searcher->search(matrix);

    }

    /**
     * The sunction receive a string representing a matrix and return a matrix.
     */
    Matrix<string> * createMatrix(string values) {
        Matrix<string> *matrix = new Matrix<string>();
        //Split the string
        char *temp = const_cast<char *>(values.c_str());
        char* temp2 = strtok(temp, ";");
        list<string> stringList;
        //While temp is not at the end of the line
        while (temp2!=NULL){
            //Pusg the string to a vector
            stringList.push_back(string(temp2));
            temp2 = strtok(NULL, ";");
        }
        //Go ovet the vectrtor and add each line to the matrix
        list<string>::iterator iter;
        iter=stringList.begin();
        while (*iter != "end") {
            string s = *iter;
            matrix->addRow(s);
            ++iter;
        }
        //Skip the word "end"
        iter++;
        //Get the start index and set the initial state of the matrix
        string initializeState = *iter;
        char *index = const_cast<char *>(initializeState.c_str());
        index = strtok(index, ",");
        int i = stoi(index);
        index = strtok(NULL, ",");
        int j = stoi(index);
        matrix->setInitialState(matrix->getStateByIndex(i, j));
        iter++;
        //Get the end index and set the goal state of the matrix
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
