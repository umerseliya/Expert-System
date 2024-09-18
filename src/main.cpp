#include <iostream>
#include <string>
#include "KnowledgeBaseBackward.h"
#include "KnowledgeBaseForward.h"
#include "VariableList.h"
#include "InferenceEngineBackward.h"
#include "InferenceEngineForward.h"

using namespace std;

int main(){
    // Initialize Knowledge Bases
    KnowledgeBaseBackward kb_backward;
    KnowledgeBaseForward kb_forward;

    // Initialize Variable Lists
    VariableList varList_backward;
    VariableList varList_forward;

    // Initialize Inference Engines
    InferenceEngineBackward ie_backward(&kb_backward, &varList_backward);
    InferenceEngineForward ie_forward(&kb_forward, &varList_forward);

    // -----------------------------
    // Backward Chaining for Diagnosis
    // -----------------------------
    cout << "=== Backward Chaining Diagnosis ===\n";
    string goal = "DIAGNOSIS"; // Automatically set the goal to DIAGNOSIS

    // Start processing
    string diagnosis;
    bool found = ie_backward.Process(goal, diagnosis);

    if(found && !diagnosis.empty()){
        cout << "\nDiagnosis: " << diagnosis << "\n";

        // Pass diagnosis to forward chaining
        varList_forward.setVariable("DISEASE", diagnosis);
    }
    else{
        cout << "\nGoal cannot be determined.\n";
        return 0;
    }

    // -----------------------------
    // Forward Chaining for Treatment
    // -----------------------------
    cout << "\n=== Forward Chaining Treatment Recommendations ===\n";
    string symptom;
    cout << "Enter the symptom for treatment recommendation: ";
    getline(cin, symptom);

    // Add initial symptom to forward chaining
    ie_forward.add_initial_symptom(symptom);

    // Process forward chaining
    ie_forward.process_forward();

    // Print treatment recommendations
    ie_forward.print_conclusions();

    return 0;
}
