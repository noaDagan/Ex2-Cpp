#include "Searcher.h"
#include <string.h>
#include <string>
#include <unordered_set>
#include <map>

#ifndef PROJECTNUM2_ASTAR_H
#define PROJECTNUM2_ASTAR_H
using namespace std;

template<class VALUE>

class ASTar : public Searcher<VALUE> {
    int numberOfNodesEvaluated;
public:
    ASTar() {
        this->numberOfNodesEvaluated=0;
    }

    VALUE search(Searchable<VALUE> *searchable) {
        vector<State<VALUE> *> open;
        vector<State<VALUE> *> close;
        vector<State<VALUE> *> successors;
        map<State<VALUE> *, double> costMap;
        State<VALUE> *initialState = searchable->getInitialState();
        open.push_back(searchable->getInitialState());
        costMap.insert(pair<State<VALUE> *, double>(initialState,
                                                    initialState->getCost()));
        char *index = const_cast<char *>(searchable->getGoalState()->getState().c_str());
        index = strtok(index, ",");
        int iGoal = stoi(index);
        index = strtok(NULL, ",");
        int jGoal = stoi(index);
        while (!open.empty()) {
            State<VALUE> *currentState = open[0];
            open.erase(open.begin());
            close.push_back(currentState);
            this->numberOfNodesEvaluated++;
            if (currentState->equal(searchable->getGoalState())) {
                return this->createBackTrace(searchable, currentState);
            }
            successors = searchable->getAllPossibleStates(currentState);
            for (int k = 0; k < successors.size(); k++) {
                State<VALUE> *tempState = successors[k];
                char *index = const_cast<char *>(tempState->getState().c_str());
                index = strtok(index, ",");
                int i = stoi(index);
                index = strtok(NULL, ",");
                int j = stoi(index);
                double h = abs(i - iGoal) + abs(j - jGoal);
                double cost = tempState->getCost() +
                              (costMap.find(currentState))->second + h;
                int openIndex = this->isValueInVector(open, tempState);
                int closeIndex = this->isValueInVector(close, tempState);
                if (costMap.count(tempState)) {
                    if (costMap.find(tempState)->second < cost) {
                        continue;
                    } else {
                        costMap.insert(
                                pair<State<VALUE> *, double>(tempState, cost));
                        tempState->setCameFrom(currentState);
                    }
                } else {
                    costMap.insert(
                            pair<State<VALUE> *, double>(tempState, cost));
                    tempState->setCameFrom(currentState);
                    open.push_back(tempState);
                }
            }
        }
    }


    int isValueInVector(vector<State<VALUE> *> open, State<VALUE> *state) {
        int vectorSize = open.size();
        for (int i = 0; i < vectorSize; ++i) {
            if (state->equal(open[i])) {
                return i;
            }

        }
        return -1;
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


};

#endif //PROJECTNUM2_ASTAR_H
