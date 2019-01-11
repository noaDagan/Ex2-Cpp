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

    //Constructor
    ASTar() {
        this->numberOfNodesEvaluated = 0;
    }

    /**
     * The function run A* algorithm and return the path from the initial state to the goal
     * state ,
     */
    VALUE search(Searchable<VALUE> *searchable) {
        vector<State<VALUE> *> open;
        vector<State<VALUE> *> close;
        vector<State<VALUE> *> successors;
        //Cost of path to a state
        map<State<VALUE> *, double> costMap;
        //Add the initial state
        State<VALUE> *initialState = searchable->getInitialState();
        open.push_back(searchable->getInitialState());
        costMap.insert(pair<State<VALUE> *, double>(initialState,
                                                    initialState->getCost()));
        //Save the index of the goal state
        char *index = const_cast<char *>(searchable->getGoalState()->getState().c_str());
        index = strtok(index, ",");
        int iGoal = stoi(index);
        index = strtok(NULL, ",");
        int jGoal = stoi(index);
        //While there are still states to visit
        while (!open.empty()) {
            //Get the first state from the open list
            State<VALUE> *currentState = open[0];
            open.erase(open.begin());
            //Mark state as visited
            close.push_back(currentState);
            this->numberOfNodesEvaluated++;
            //If reached the goal state return the path
            if (currentState->equal(searchable->getGoalState())) {
                return this->createBackTrace(searchable, currentState);
            }
            //Get all the state successors and check each successor
            successors = searchable->getAllPossibleStates(currentState);
            for (int k = 0; k < successors.size(); k++) {
                //Get the successor index
                State<VALUE> *tempState = successors[k];
                char *index = const_cast<char *>(tempState->getState().c_str());
                index = strtok(index, ",");
                int i = stoi(index);
                index = strtok(NULL, ",");
                int j = stoi(index);
                //Claculate h and the cost of the path until this successor
                double h = abs(i - iGoal) + abs(j - jGoal);
                double cost = tempState->getCost() +
                              (costMap.find(currentState))->second + h;
                int openIndex = this->isValueInVector(open, tempState);
                int closeIndex = this->isValueInVector(close, tempState);
                //If this state was already visited
                if (costMap.count(tempState)) {
                    //If the new cost is more then the previous one  continue
                    if (costMap.find(tempState)->second < cost) {
                        continue;
                        //Else replace the state path cost
                    } else {
                        costMap.insert(
                                pair<State<VALUE> *, double>(tempState, cost));
                        tempState->setCameFrom(currentState);
                    }
                    //Insert the stste and save his cost
                } else {
                    costMap.insert(
                            pair<State<VALUE> *, double>(tempState, cost));
                    tempState->setCameFrom(currentState);
                    open.push_back(tempState);
                }
            }
        }
    }


    /**
     * The function receive a state vectoe and a state and returns -1 is the state is not in the vector
     * else it returns the state position in the vector
     */
    int isValueInVector(vector<State<VALUE> *> open, State<VALUE> *state) {
        int vectorSize = open.size();
        //Go over the vectoe and compare his state wuth the state received
        for (int i = 0; i < vectorSize; ++i) {
            if (state->equal(open[i])) {
                return i;
            }

        }
        return -1;
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
            //Get the index of the current state
            State<VALUE> *preState = goalState->getCameFrom();
            string nameCurr = goalState->getState();
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

            goalState = goalState->getCameFrom();
        }
        //Return the result.
        int resultLen = result.length();
        result = result.substr(0, resultLen - 2);
        return result;

    }
    //Distructor
    ~ASTar() {};

};

#endif //PROJECTNUM2_ASTAR_H
