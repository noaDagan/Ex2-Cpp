
#include <string>

#ifndef PROJECTNUM2_CACHMANNAGER_H
#define PROJECTNUM2_CACHMANNAGER_H
using namespace std;

template<class PROBLEM, class SOLUTION>
class CacheManager {
public:
    /**
     * The function returns if the solution to a given problem  was already solved and saved.
     */
    virtual bool haveSolution(PROBLEM problem) = 0;

    /**
     * The function returns returns a saved solution to a given problem.
     */
    virtual SOLUTION getSolution(PROBLEM problem) = 0;

    /**
     * Thr function receive a problem and solution and save them.
     */
    virtual void saveSolution(PROBLEM problem, SOLUTION solution) = 0;

};


#endif //PROJECTNUM2_CACHMANNAGER_H
