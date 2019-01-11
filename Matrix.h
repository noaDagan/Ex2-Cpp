#include "Searchable.h"
#include <vector>
#include "State.h"
#include "string"
#include <string.h>

#ifndef PROJECTNUM2_MATRIX_H
#define PROJECTNUM2_MATRIX_H

template<class VALUE>
class Matrix : public Searchable<VALUE> {
    vector<vector<State<VALUE> *>> matrixArray;
    State<VALUE> *initialState;
    State<VALUE> *goalState;
    int countRow;

public:

    //Constructor
    Matrix() {
        this->countRow = 0;
    }


    /**
     * The function retuns the initial state of the searchable object
     */
    State<VALUE> *getInitialState() {
        return this->initialState;
    }

    /**
     * The function retuns the goal state of the searchable object
     */
    State<VALUE> *getGoalState() {
        return this->goalState;
    }

    /**
     * The function set the goal state
     */
    void setGoalState(State<VALUE> *goalState) {
        this->goalState = goalState;
    }


    /**
    * The function set the initial state
    */
    void setInitialState(State<VALUE> *initialState) {
        this->initialState = initialState;
    }

    /**
     * The sunction receive a string of number and add the number as a row of the matrix.
     */
    void addRow(string row) {
        vector<State<VALUE> *> rowVector;
        double cost;
        //Split the row
        char *temp = const_cast<char *>(row.c_str());
        temp = strtok(temp, ",");
        int col = 0;
        //While temp is not at the end of the line
        while (temp != NULL) {
            //Create a new state
            cost = atof(temp);
            temp = strtok(NULL, ",");
            State<string> *newState = new State<string>();
            //Set the state name to be the corresponding index in the matrix
            string name = to_string(this->countRow) + "," + to_string(col);
            newState->setState(name);
            //Set the state cost to be the number from the line
            newState->setCost(cost);
            rowVector.push_back(newState);
            col++;
        }
        this->matrixArray.push_back(rowVector);
        this->countRow++;

    }

    /**
     * The function returns a state from the matrix according of the index received.
     */
    State<VALUE> *getStateByIndex(int row, int col) {
        return this->matrixArray[row][col];
    }


    /**
     * The function retuns  a vector of all the seccesors the the given state
     */
    vector<State<string> *> getAllPossibleStates(State<string> *state) {
        vector<State<string> *> possibleStates;
        //Get the state index
        string name = state->getState();
        char *index = const_cast<char *>(name.c_str());
        index = strtok(index, ",");
        int i = stoi(index);
        index = strtok(NULL, ",");
        int j = stoi(index);
        int sizeOfRow = this->matrixArray[i].size();
        //If the index is not in the first row add to the vector the state above the state received
        if (i != 0) {

            possibleStates.push_back(this->matrixArray[i - 1][j]);
        }
        //If the index is not in the right most col add to the vector the state right to the state received
        if (j != 0) {
            possibleStates.push_back(this->matrixArray[i][j - 1]);
        }
        //If the index is not in the last col add to the vector the state below the state received
        if (j < sizeOfRow - 1) {
            possibleStates.push_back(this->matrixArray[i][j + 1]);
        }
        //If the index is not in the first row add to the vector the state above the state received
        if (i < this->countRow - 1) {
            possibleStates.push_back(this->matrixArray[i + 1][j]);
        }
        return possibleStates;
    }
    //Distructor
    ~Matrix() {
        for (int i = 0; i <this->matrixArray.size() ; ++i) {
            vector<State<string> *> temp=this->matrixArray[i];
            for (int j = 0; j <temp.size() ; ++j) {
                delete temp[j];
            }
        }
    };
};


#endif //PROJECTNUM2_MATRIX_H
