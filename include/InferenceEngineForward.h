#ifndef INFERENCEENGINEFORWARD_H
#define INFERENCEENGINEFORWARD_H

#include "KnowledgeBaseForward.h"
#include "VariableList.h"
#include <string>
#include <unordered_map>
#include <queue>
#include <vector>

using namespace std;

class InferenceEngineForward {
private:
    KnowledgeBaseForward* kb;
    VariableList* varList;
    vector<string> derivedConclusions;
    queue<string> conclusionQueue;

public:
    InferenceEngineForward(KnowledgeBaseForward* knowledgeBase, VariableList* variables);
    
    // Function 1: search_cvl
    bool search_cvl(const string& variable, int& Ci);
    
    // Function 2: clause_to_rule
    int clause_to_rule(int Ci);
    
    // Function 3: update_VL_forward
    bool update_VL_forward(int Ci);
    
    // Function 4: validate_Ri_forward
    bool validate_Ri_forward(int Ri);
    
    // Function 5: process_forward
    void process_forward();
    
    // Function to add initial treatment symptom
    void add_initial_symptom(const string& symptom);
    
    // Function to print derived conclusions
    void print_conclusions();
};

#endif // INFERENCEENGINEFORWARD_H
