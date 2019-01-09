#include "Searchable.h"
#ifndef PROJECTNUM2_SEARCHER_H
#define PROJECTNUM2_SEARCHER_H

template <class VALUE>
class Searcher {
public:
    virtual VALUE search (Searchable<VALUE>* searchable) = 0;
    virtual int getNumberOfNodesEvaluated() = 0;
};

#endif //PROJECTNUM2_SEARCHER_H
