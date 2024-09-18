#include "RuleForward.h"

// Constructor Implementation
RuleForward::RuleForward(int num, const unordered_map<string, string>& cond, const string& concl)
    : ruleNumber(num), conditions(cond), conclusion(concl) {}
