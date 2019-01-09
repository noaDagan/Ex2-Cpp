
#include <string>
#ifndef PROJECTNUM2_CACHMANNAGER_H
#define PROJECTNUM2_CACHMANNAGER_H
using namespace std;

template <class PROBLEM, class SOLUTION>
class CacheManager {
public:
    virtual bool haveSolution(PROBLEM problem) = 0;
    virtual SOLUTION getSolution(PROBLEM problem) = 0;
    virtual void saveSolution(PROBLEM problem, SOLUTION solution) = 0;

};


#endif //PROJECTNUM2_CACHMANNAGER_H
