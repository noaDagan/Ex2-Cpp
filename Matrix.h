#include "Searchable.h"
#include <vector>
#include "State.h"
#include "string"
#include <string.h>
#ifndef PROJECTNUM2_MATRIX_H
#define PROJECTNUM2_MATRIX_H

template < class VALUE>
class Matrix : public Searchable <VALUE> {
    vector<vector<State<VALUE>*>> matrixArray;
    State <VALUE>* initialState;
    State <VALUE>* goalState;
    int countRow;

public:
    Matrix() {
        this->countRow = 0;
    }


     State<VALUE>* getInitialState() {
        return this->initialState;
    }


     State<VALUE>* getGoalState() {
        return this->goalState;
    }


    void setGoalState(State<VALUE>* goalState) {
        this->goalState = goalState;
    }


    void setInitialState(State<VALUE>* initialState) {
        this->initialState = initialState;
    }

    void addRow(string row) {
        vector<State<VALUE>*> rowVector;
        double cost;
        char *temp = const_cast<char *>(row.c_str());
        temp = strtok(temp, ",");
        int col = 0;
        while (temp != NULL) {
            cost = atof(temp);
            temp = strtok(NULL, ",");
            State<string>* newState = new State<string>();
            string name = to_string(this->countRow) + "," + to_string(col);
            newState->setState(name);
            newState->setCost(cost);
            rowVector.push_back(newState);
            col++;
        }
        this->matrixArray.push_back(rowVector);
        this->countRow++;

    }


    State<VALUE>*getStateByIndex(int row, int col) {
        return this->matrixArray[row][col];
    }


     vector<State<string>*> getAllPossibleStates(State<string>* state) {
        vector<State<string>*> possibleStates;
        string name = state->getState();
        char *index = const_cast<char *>(name.c_str());
        index = strtok(index, ",");
        int i = stoi(index);
        index = strtok(NULL, ",");
        int j = stoi(index);
        int sizeOfRow = this->matrixArray[i].size();
        if (i != 0) {

            possibleStates.push_back(this->matrixArray[i - 1][j]);
        }
        if (j != 0) {
            possibleStates.push_back(this->matrixArray[i][j - 1]);
        }
        if (j < sizeOfRow - 1) {
            possibleStates.push_back(this->matrixArray[i][j + 1]);
        }
        if (i < this->countRow-1) {
            possibleStates.push_back(this->matrixArray[i + 1][j]);
        }
        return possibleStates;
    }

};


#endif //PROJECTNUM2_MATRIX_H
