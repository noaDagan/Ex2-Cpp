#include "Searchable.h"

#ifndef PROJECTNUM2_SEARCHER_H
#define PROJECTNUM2_SEARCHER_H

template<class VALUE>
class Searcher {
public:

    /**
     * The function receive a searchble object, run an algoritem and return his solution
     */
    virtual VALUE search(Searchable<VALUE> *searchable) = 0;

    /**
     * The function returns the number od nodes evaluated
    */
    virtual int getNumberOfNodesEvaluated() = 0;
};

#endif //PROJECTNUM2_SEARCHER_H
