#include "State.h"
#include <list>
#include <vector>

#ifndef PROJECTNUM2_SEARCHABLE_H
#define PROJECTNUM2_SEARCHABLE_H

using namespace std;

template<class VALUE>
class Searchable {
public:

    /**
     * The function retuns the initial state of the searchable object
     */
    virtual State<VALUE> *getInitialState() = 0;

    /**
     * The function retuns the goal state of the searchable object
     */
    virtual State<VALUE> *getGoalState() = 0;

    /**
     * The function retuns  a vector of all the seccesors the the given state
     */
    virtual vector<State<VALUE> *> getAllPossibleStates(State<VALUE> *s) = 0;
};

#endif //PROJECTNUM2_SEARCHABLE_H
