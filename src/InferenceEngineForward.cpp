#include "InferenceEngineForward.h"
#include <iostream>
#include <algorithm>

// Constructor Implementation
InferenceEngineForward::InferenceEngineForward(KnowledgeBaseForward* knowledgeBase, VariableList* variables)
    : kb(knowledgeBase), varList(variables) {}

// Function 1: search_cvl
bool InferenceEngineForward::search_cvl(const string& variable, int& Ci) {
    // In forward chaining, find rules where SYMPTOM matches the variable
    for(auto& rule : kb->rules){
        auto it = rule->conditions.find("SYMPTOM");
        if(it != rule->conditions.end() && it->second == variable){
            Ci = rule->ruleNumber;
            return true;
        }
    }
    return false;
}

// Function 2: clause_to_rule
int InferenceEngineForward::clause_to_rule(int Ci) {
    // Assuming clause number corresponds to rule number
    return Ci;
}

// Function 3: update_VL_forward
bool InferenceEngineForward::update_VL_forward(int Ci) {
    // Find the rule with rule number Ci
    RuleForward* rule = nullptr;
    for(auto& r : kb->rules){
        if(r->ruleNumber == Ci){
            rule = r.get();
            break;
        }
    }
    if(rule == nullptr)
        return false;

    // Check and instantiate variables in conditions
    for(auto& cond : rule->conditions){
        if(!varList->isInstantiated(cond.first)){
            string response;
            cout << "Enter value for " << cond.first << " (expected: " << cond.second << "): ";
            getline(cin, response);
            // For simplicity, assume user inputs correct values
            // Convert to uppercase for consistency
            transform(response.begin(), response.end(), response.begin(), ::toupper);
            varList->setVariable(cond.first, response);
        }
    }
    return true;
}

// Function 4: validate_Ri_forward
bool InferenceEngineForward::validate_Ri_forward(int Ri) {
    // Find the rule
    RuleForward* rule = nullptr;
    for(auto& r : kb->rules){
        if(r->ruleNumber == Ri){
            rule = r.get();
            break;
        }
    }
    if(rule == nullptr)
        return false;

    // Check if all conditions are satisfied
    for(auto& cond : rule->conditions){
        if(!varList->isInstantiated(cond.first) || varList->getVariable(cond.first) != cond.second){
            return false;
        }
    }

    // If satisfied, add conclusion to derived conclusions and queue
    derivedConclusions.push_back(rule->conclusion);
    conclusionQueue.push(rule->conclusion);
    return true;
}

// Function 5: process_forward
void InferenceEngineForward::process_forward() {
    while(!conclusionQueue.empty()){
        string currentConclusion = conclusionQueue.front();
        conclusionQueue.pop();

        // Find and process rules that have this conclusion as a condition
        for(auto& rule : kb->rules){
            bool trigger = true;
            for(auto& cond : rule->conditions){
                if(cond.first == "DISEASE" && cond.second == currentConclusion){
                    // Validate the rule
                    if(validate_Ri_forward(rule->ruleNumber)){
                        // Rule validated, enqueue the conclusion
                        // Already handled in validate_Ri_forward
                    }
                }
            }
        }
    }
}

// Function to add initial treatment symptom
void InferenceEngineForward::add_initial_symptom(const string& symptom) {
    varList->setVariable("SYMPTOM", symptom);
    conclusionQueue.push(symptom);
}

// Function to print derived conclusions
void InferenceEngineForward::print_conclusions() {
    cout << "\n--- Treatment Recommendations ---\n";
    for(auto& concl : derivedConclusions){
        cout << "- " << concl << "\n";
    }
}
