#include <unordered_set>
#include "Searchable.h"
#include <string.h>

#ifndef PROJECTNUM2_BESTFIRSRTSEARCHE_H
#define PROJECTNUM2_BESTFIRSRTSEARCHE_H


template<class VALUE>
class BestFirstSearch : public Searcher<VALUE> {
    int numberOfNodesEvaluated;
public:
    BestFirstSearch() {
        this->numberOfNodesEvaluated = 0;
    }

    VALUE
    createBackTrace(Searchable<VALUE> *searchable, State<VALUE> *goalState) {
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
            } else if (iPrev > iCurr) {
                result = "Up, " + result;
            } else if (jCurr < jPrev) {
                result = "Left, " + result;
            }

            goalState = goalState->getCameFrom();
        }
        int resultLen = result.length();
        result = result.substr(0, resultLen - 2);
        return result;
    }

    vector<State<VALUE> *>
    sortVector(vector<State<VALUE> *> open, State<VALUE> *state) {
        vector<State<VALUE> *> resultVector;
        int vectorSize = open.size();
        int i = 0;
        if (vectorSize == 0) {
            resultVector.push_back(state);
        } else {
            State<VALUE> *temp = open[i];
            if (state->getCost() < temp->getCost()) {
                resultVector.push_back(state);
            } else {
                resultVector.push_back(temp);
            }
        }
        return resultVector;
    }

    VALUE search(Searchable<VALUE> *searchable) {
        vector<State<VALUE> *> open;
        unordered_set<State<VALUE> *> close;
        vector<State<VALUE> *> successors;
        open.push_back(searchable->getInitialState());
        while (!open.empty()) {
            State<VALUE> *currentState = open[0];
            open.erase(open.begin());
            close.insert(currentState);
            this->numberOfNodesEvaluated++;
            if (currentState->equal(searchable->getGoalState())) {
                return this->createBackTrace(searchable, currentState);
            }
            successors = searchable->getAllPossibleStates(currentState);
            for (int i = 0; i < successors.size(); i++) {
                State<VALUE> *tempState = successors[i];
                if (!close.count(tempState)) {
                    tempState->setCameFrom(currentState);
                    open = sortVector(open, tempState);
                }
            }
        }
    }

    int getNumberOfNodesEvaluated() {
        return this->numberOfNodesEvaluated;
    }


};

#endif //PROJECTNUM2_BESTFIRSRTSEARCHE_H
