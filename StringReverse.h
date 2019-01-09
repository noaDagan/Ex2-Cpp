#include "Solver.h"
#include <string>

#ifndef PROJECTNUM2_STRINGREVERSER_H
#define PROJECTNUM2_STRINGREVERSER_H

using namespace std;

class StringReverse : public Solver <string,string> {
public:
    StringReverse();
    string solve(string problem);
};


#endif //PROJECTNUM2_STRINGREVERSER_H
