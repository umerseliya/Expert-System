#include "KnowledgeBaseForward.h"

// Constructor Implementation
KnowledgeBaseForward::KnowledgeBaseForward() {
    // Initialize forward chaining rules
    // Example Rules:
    rules.emplace_back(make_unique<RuleForward>(10, 
        unordered_map<string, string>{{"DISEASE", "Coronary Artery Disease"}, {"SYMPTOM", "Chest pain or discomfort"}}, 
        "Lifestyle changes (diet, exercise, smoking cessation)"));

    rules.emplace_back(make_unique<RuleForward>(20, 
        unordered_map<string, string>{{"DISEASE", "Coronary Artery Disease"}, {"SYMPTOM", "Pain radiating to arms, neck, jaw, or back"}}, 
        "Medications (statins, beta blockers)"));

    // ... Add all forward chaining rules here following the same pattern

    // Additional example rules:
    rules.emplace_back(make_unique<RuleForward>(30, 
        unordered_map<string, string>{{"DISEASE", "Heart Attack"}, {"SYMPTOM", "Severe chest pain lasting over 15 minutes"}}, 
        "Immediate administration of aspirin"));

    rules.emplace_back(make_unique<RuleForward>(40, 
        unordered_map<string, string>{{"DISEASE", "Heart Attack"}, {"SYMPTOM", "Shortness of breath"}}, 
        "Thrombolytic therapy (clot busting drugs)"));

    // ... Continue adding all rules as per your provided list
}
