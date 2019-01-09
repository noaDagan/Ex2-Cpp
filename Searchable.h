#include "State.h"
#include <list>
#include <vector>
#ifndef PROJECTNUM2_SEARCHABLE_H
#define PROJECTNUM2_SEARCHABLE_H

using namespace std;

template <class VALUE>
class Searchable {
public:
    virtual State <VALUE>* getInitialState() = 0;
    virtual State <VALUE>* getGoalState() = 0;
    virtual vector<State<VALUE>*> getAllPossibleStates(State<VALUE>* s) = 0;
};
#endif //PROJECTNUM2_SEARCHABLE_H
