

#ifndef PROJECTNUM2_SOLVER_H
#define PROJECTNUM2_SOLVER_H


template<class PROBLEM, class SOLUTION>
class Solver {
public:
    virtual SOLUTION solve(PROBLEM problem) = 0;
};


#endif //PROJECTNUM2_SOLVER_H
