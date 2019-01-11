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

#ifndef PROJECTNUM2_DFS_H
#define PROJECTNUM2_DFS_H
using namespace std;

template<class VALUE>
class DFS : public Searcher<VALUE> {
    int numberOfNodesEvaluated;
public:
    //Constructor
    DFS() {
        this->numberOfNodesEvaluated = 0;
    }

    /**
     * The function run the DFS algorithm
     */
    void DFSRecursive(State<VALUE> *state, unordered_set<State<VALUE> *> close,
                      Searchable<VALUE> *searchable) {
        vector<State<VALUE> *> successors;
        State<VALUE> *tempState;
        this->numberOfNodesEvaluated++;
        //If reached the goal state return
        if (searchable->getGoalState()->equal(state)) {
            return;
        }
        //Get all the state successors and check each successor
        successors = searchable->getAllPossibleStates(state);
        for (int i = 0; i < successors.size(); i++) {
            tempState = successors[i];
            //If the successor was not visited add it to the close list
            if ((!close.count(tempState))) {
                close.insert(tempState);
                tempState->setCameFrom(state);

            }
        }
        DFSRecursive(tempState, close, searchable);
    }


     /**
     * The fuction run the DFS algorithm and return the path from the initial state to the goal
     */
    VALUE search(Searchable<VALUE> *searchable) {
        unordered_set<State<VALUE> *> close;
        //Add the initial state to the close list
        State<VALUE> *initState = searchable->getInitialState();
        close.insert(initState);
        //Run DFS
        this->DFSRecursive(initState, close, searchable);
        //Return the path of the result
        return this->createBackTrace(searchable, searchable->getGoalState());
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

    ~DFS(){};
};


#endif //PROJECTNUM2_DFS_H
