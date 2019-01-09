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
    DFS() {
        this->numberOfNodesEvaluated = 0;
    }

    void DFSRecursive(State<VALUE>* state,unordered_set<State<VALUE> *> close,Searchable<VALUE> *searchable) {
        vector<State<VALUE> *> successors;
        close.insert(state);
        this->numberOfNodesEvaluated++;
//        if (state->equal(searchable->getGoalState())) {
//            return state;
//        }
        successors = searchable->getAllPossibleStates(state);
        for (int i = 0; i < successors.size(); i++) {
            if (!close.count(successors[i])) {
                State<VALUE> *tempState = successors[i];
                tempState->setCameFrom(state);
                 DFSRecursive(tempState, close, searchable);
            }

        }
    }
    VALUE search(Searchable<VALUE> *searchable) {
        unordered_set<State<VALUE> *> close;
        State<VALUE>* initilateState = searchable->getInitialState();
        //close.insert(initilateState);
        this->DFSRecursive(initilateState,close,searchable);
        return this->createBackTrace(searchable,searchable->getGoalState());
    }

    int getNumberOfNodesEvaluated() {
        return this->numberOfNodesEvaluated;

    }

    VALUE createBackTrace(Searchable<VALUE> *searchable, State<VALUE> *goalState) {
        string result = "";
        State<VALUE> *startState = searchable->getInitialState();
        while (!goalState->equal(startState)) {
            State<VALUE> *preState = goalState->getCameFrom();
            string nameCurr = goalState->getState();
            char *index = const_cast<char *>(nameCurr.c_str());
            index = strtok(index, ",");
            int iCurr = stoi(index);
            index = strtok(NULL, ",");
            int jCurr = stoi(index);
            string namePrev = preState->getState();
            char *index2 = const_cast<char *>(namePrev.c_str());
            index2 = strtok(index2, ",");
            int iPrev = stoi(index2);
            index2 = strtok(NULL, ",");
            int jPrev = stoi(index2);
            if (iPrev < iCurr) {
                result = "Down, " + result;
            } else if (jCurr > jPrev) {
                result = "Right, " + result;
            } else if (iPrev < iCurr) {
                result = "Up, " + result;
            } else if (jCurr < jPrev) {
                result = "Left, " + result;
            }

            goalState=goalState->getCameFrom();
        }
        int resultLen = result.length();
        result = result.substr(0, resultLen - 2);
        return result;
    }



};


#endif //PROJECTNUM2_DFS_H
