

#ifndef PROJECTNUM2_SOLVER_H
#define PROJECTNUM2_SOLVER_H


template<class PROBLEM, class SOLUTION>
class Solver {
public:
    /**
     * The function receive a problem and return a solution.
     */
    virtual SOLUTION solve(PROBLEM problem) = 0;
};


#endif //PROJECTNUM2_SOLVER_H
