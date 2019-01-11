
#include "StringReverse.h"

//Constructor
StringReverse::StringReverse() {}

/**
 * The function receive a string as problem and return a reverse string
*/
string StringReverse::solve(string problem) {
    string result = "";
    //Go over the string and reverse it
    int stringLength =  problem.length() - 1;
    for(int i = stringLength; i >= 0; i--) {
        result += problem[i];
    }
    return result;
}