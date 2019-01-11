#include "Searcher.h"
#include "list"
#include "State.h"
#include "Searchable.h"
#include <string.h>
#include <string>
#include <vector>
#include <unordered_set>
#include<vector>
#include <queue>

#ifndef PROJECTNUM2_BFS_H
#define PROJECTNUM2_BFS_H

using namespace std;

template<class VALUE>
class BFS : public Searcher<VALUE> {
    int numberOfNodesEvaluated;
public:

    //Constructor
    BFS() {
        this->numberOfNodesEvaluated = 0;

    }

    /**
     * The fuction run the BFS algorithm and return the path from the initial state to the goal
     */
    VALUE search(Searchable<VALUE> *searchable) {
        vector<State<VALUE> *> open;
        unordered_set<State<VALUE> *> close;
        vector<State<VALUE> *> successors;
        //Add the initial state
        open.push_back(searchable->getInitialState());
        //While there are still states to visit
        while (!open.empty()) {
            //Get the first state from the open list
            State<VALUE> *currentState = open[0];
            open.erase(open.begin());
            //Add the state to the close list
            close.insert(currentState);
            this->numberOfNodesEvaluated++;
            //If reached the goal state return the path
            if (currentState->equal(searchable->getGoalState())) {
                return this->createBackTrace(searchable, currentState);
            }
            //Get all the state successors and check each successor
            successors = searchable->getAllPossibleStates(currentState);
            for (int i = 0; i < successors.size(); i++) {
                //If the successor was not viseted yet add it to the open vector
                if (!close.count(successors[i])&&(!this->isValuInVector(open,successors[i]))) {
                    State<VALUE> *tempState = successors[i];
                    tempState->setCameFrom(currentState);
                    open.push_back(tempState);
                }
            }
        }
    }

    /**
     * The function receive a state vectoe and a state and returns if the state is in the vector
     */
    bool isValuInVector(vector<State<VALUE> *> open, State<VALUE> *state) {
        int vectorSize = open.size();
        //Go over the vector and compare the states to the state received
        for (int i = 0; i < vectorSize; ++i) {
            if (state->equal(open[i])) {
                return true;
            }

        }
        return false;
    }


    /**
    * The function returns the number od nodes evaluated
    */
    int getNumberOfNodesEvaluated() {
        return this->numberOfNodesEvaluated;
    }

    /**
     * The function receive a searchable object and the goal state and return
     * a  backTrace oh the path to reach the goal state
     */
    VALUE createBackTrace(Searchable<VALUE> *searchable, State<VALUE> *goalState) {
        string result = "";
        State<VALUE> *startState = searchable->getInitialState();
        //While the state checked is not  the initial state
        while (!goalState->equal(startState)) {
            State<VALUE> *preState = goalState->getCameFrom();
            string nameCurr = goalState->getState();
            //Get the index of the current state
            char *index = const_cast<char *>(nameCurr.c_str());
            index = strtok(index, ",");
            int iCurr = stoi(index);
            index = strtok(NULL, ",");
            int jCurr = stoi(index);
            //Get the index of the previous state
            string namePrev = preState->getState();
            char *index2 = const_cast<char *>(namePrev.c_str());
            index2 = strtok(index2, ",");
            int iPrev = stoi(index2);
            index2 = strtok(NULL, ",");
            int jPrev = stoi(index2);
            //Compare the index i and j to know how we reached the current state
            if (iPrev < iCurr) {
                result = "Down, " + result;
            } else if (jCurr > jPrev) {
                result = "Right, " + result;
            } else if (iPrev > iCurr) {
                result = "Up, " + result;
            } else if (jCurr < jPrev) {
                result = "Left, " + result;
            }

            goalState=goalState->getCameFrom();
        }
        //Return the result.
        int resultLen = result.length();
        result = result.substr(0, resultLen - 2);
        return result;

    }

    ~BFS(){};
};


#endif //PROJECTNUM2_BFS_H
