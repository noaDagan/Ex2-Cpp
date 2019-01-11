#include <unordered_set>
#include "Searchable.h"
#include <string.h>

#ifndef PROJECTNUM2_BESTFIRSRTSEARCHE_H
#define PROJECTNUM2_BESTFIRSRTSEARCHE_H


template<class VALUE>
class BestFirstSearch : public Searcher<VALUE> {
    int numberOfNodesEvaluated;
public:

    //Constructor
    BestFirstSearch() {
        this->numberOfNodesEvaluated = 0;
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
            //Compare the index i and j to know how we reached the current state
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
        //Return the result.
        int resultLen = result.length();
        result = result.substr(0, resultLen - 2);
        return result;
    }

    /**
     * The function receive a state vector and a state,The function adds the state so that the vector is
     * sorted from smallest to larger
     */
    vector<State<VALUE> *> sortVector(vector<State<VALUE> *> open, State<VALUE> *state) {
        vector<State<VALUE> *> resultVector;
        int vectorSize = open.size();
        int i = 0;
        //If the vector is empty pusg the state
        if (vectorSize == 0) {
            resultVector.push_back(state);
        } else {
            //Else push the state wuth the lowest cost
            State<VALUE> *temp = open[i];
            if (state->getCost() < temp->getCost()) {
                resultVector.push_back(state);
            } else {
                resultVector.push_back(temp);
            }
        }
        return resultVector;
    }

    /**
     * The fuction run the best first search algorithm and return the path from the initial state to the goal
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
                State<VALUE> *tempState = successors[i];
                //If the state was not visted yet add it to the open list and sort
                if (!close.count(tempState)) {
                    tempState->setCameFrom(currentState);
                    open = sortVector(open, tempState);
                }
            }
        }
    }


    /**
    * The function returns the number od nodes evaluated
    */
    int getNumberOfNodesEvaluated() {
        return this->numberOfNodesEvaluated;
    }

    ~BestFirstSearch(){};

};

#endif //PROJECTNUM2_BESTFIRSRTSEARCHE_H
