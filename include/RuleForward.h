#ifndef RULEFORWARD_H
#define RULEFORWARD_H

#include <string>
#include <unordered_map>

using namespace std;

class RuleForward {
public:
    int ruleNumber;
    unordered_map<string, string> conditions; // Variable -> Value
    string conclusion;

    RuleForward(int num, const unordered_map<string, string>& cond, const string& concl);
};

#endif // RULEFORWARD_H
