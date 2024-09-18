#include "RuleBackward.h"

// Constructor Implementation
RuleBackward::RuleBackward(int num, const unordered_map<string, string>& cond, const string& concl)
    : ruleNumber(num), conditions(cond), conclusion(concl) {}
