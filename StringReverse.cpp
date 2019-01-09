
#include "StringReverse.h"

StringReverse::StringReverse() {}

string StringReverse::solve(string problem) {
    string result = "";
    int stringLength =  problem.length() - 1;
    for(int i = stringLength; i >= 0; i--) {
        result += problem[i];
    }
    return result;
}