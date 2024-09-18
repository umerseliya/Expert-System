#ifndef INFERENCEENGINEBACKWARD_H
#define INFERENCEENGINEBACKWARD_H

#include "KnowledgeBaseBackward.h"
#include "VariableList.h"
#include <string>
#include <unordered_map>
#include <queue>

using namespace std;

class InferenceEngineBackward {
private:
    KnowledgeBaseBackward* kb;
    VariableList* varList;
    unordered_map<string, string> derivedVariables;
    vector<string> conclusionList; // List of possible conclusions
    unordered_map<string, int> conclusionToRule; // Conclusion -> Rule Number

public:
    InferenceEngineBackward(KnowledgeBaseBackward* knowledgeBase, VariableList* variables);
    
    // Function 1: search_con
    bool search_con(const string& variable, int& Ri);
    
    // Function 2: rule_to_clause
    int rule_to_clause(int Ri);
    
    // Function 3: update_VL
    bool update_VL(int Ci);
    
    // Function 4: validate_Ri
    bool validate_Ri(int Ri, string& conclusion);
    
    // Function 5: Process
    bool Process(const string& goalVariable, string& result);
};

#endif // INFERENCEENGINEBACKWARD_H
