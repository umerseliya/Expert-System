#ifndef RULEBACKWARD_H
#define RULEBACKWARD_H

#include <string>
#include <unordered_map>

using namespace std;

class RuleBackward {
public:
    int ruleNumber;
    unordered_map<string, string> conditions; // Variable -> Value
    string conclusion;

    RuleBackward(int num, const unordered_map<string, string>& cond, const string& concl);
};

#endif // RULEBACKWARD_H
