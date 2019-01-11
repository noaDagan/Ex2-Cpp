#include "Solver.h"
#include <string>

#ifndef PROJECTNUM2_STRINGREVERSER_H
#define PROJECTNUM2_STRINGREVERSER_H

using namespace std;

class StringReverse : public Solver<string, string> {
public:
    //Constructor
    StringReverse();

    /**
     * The function receive a string as problem and return a reverse string
     */
    string solve(string problem);
};


#endif //PROJECTNUM2_STRINGREVERSER_H
