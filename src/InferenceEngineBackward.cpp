#include "InferenceEngineBackward.h"
#include <iostream>
#include <algorithm>

// Constructor Implementation
InferenceEngineBackward::InferenceEngineBackward(KnowledgeBaseBackward* knowledgeBase, VariableList* variables)
    : kb(knowledgeBase), varList(variables) {
    // Initialize conclusion list and mapping
    for(auto& rule : kb->rules){
        conclusionList.push_back(rule->conclusion);
        conclusionToRule[rule->conclusion] = rule->ruleNumber;
    }
}

// Function 1: search_con
bool InferenceEngineBackward::search_con(const string& variable, int& Ri) {
    // Find the rule number corresponding to the conclusion
    auto it = conclusionToRule.find(variable);
    if(it != conclusionToRule.end()){
        Ri = it->second;
        return true;
    }
    return false;
}

// Function 2: rule_to_clause
int InferenceEngineBackward::rule_to_clause(int Ri) {
    // Assuming rules are sequenced like 10,20,30,... hence use the second formula
    // CLAUSE NUMBER (Ci) = 4* (RULE NUMBER / 10 - 1) + 1
    return 4 * (Ri / 10 - 1) + 1;
}

// Function 3: update_VL
bool InferenceEngineBackward::update_VL(int Ci) {
    // For backward chaining, starting from Ci, ask up to 4 questions
    // Here, Ci is used as an index; since we don't have a list, we'll interpret Ci as position
    // For simplicity, we'll map Ci to rule index
    // Ci starts at 1, so rule index is (Ci-1)/4
    int ruleIndex = (Ci -1 ) / 4;
    if(ruleIndex < 0 || ruleIndex >= kb->rules.size())
        return false;

    RuleBackward* rule = kb->rules[ruleIndex].get();
    for(auto& cond : rule->conditions){
        if(!varList->isInstantiated(cond.first)){
            string response;
            cout << "Is " << cond.first << " (YES/NO): ";
            getline(cin, response);
            // Convert to uppercase for consistency
            transform(response.begin(), response.end(), response.begin(), ::toupper);
            if(response != "YES" && response != "NO"){
                cout << "Invalid input. Assuming NO.\n";
                response = "NO";
            }
            varList->setVariable(cond.first, response);
        }
    }
    return true;
}

// Function 4: validate_Ri
bool InferenceEngineBackward::validate_Ri(int Ri, string& conclusion) {
    // Find the rule
    RuleBackward* rule = nullptr;
    for(auto& r : kb->rules){
        if(r->ruleNumber == Ri){
            rule = r.get();
            break;
        }
    }
    if(rule == nullptr)
        return false;

    // Check if all conditions are satisfied
    bool valid = true;
    for(auto& cond : rule->conditions){
        if(!varList->isInstantiated(cond.first) || varList->getVariable(cond.first) != cond.second){
            valid = false;
            break;
        }
    }

    if(valid){
        conclusion = rule->conclusion;
        return true;
    }
    return false;
}

// Function 5: Process
bool InferenceEngineBackward::Process(const string& goalVariable, string& result) {
    queue<string> goals;
    goals.push(goalVariable);

    while(!goals.empty()){
        string currentGoal = goals.front();
        goals.pop();

        if(varList->isInstantiated(currentGoal)){
            // Goal already instantiated
            result = varList->getVariable(currentGoal);
            return true;
        }

        int Ri;
        if(!search_con(currentGoal, Ri)){
            cout << "No rule found to infer " << currentGoal << ".\n";
            continue;
        }

        int Ci = rule_to_clause(Ri);
        if(!update_VL(Ci)){
            cout << "Failed to update variable list for rule " << Ri << ".\n";
            continue;
        }

        string conclusion;
        if(validate_Ri(Ri, conclusion)){
            varList->setVariable(currentGoal, conclusion);
            result = conclusion;
            return true;
        }
        else{
            // Conditions not satisfied, continue with next conclusion
            continue;
        }
    }
    return false;
}
