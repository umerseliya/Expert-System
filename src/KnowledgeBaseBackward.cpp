#include "KnowledgeBaseBackward.h"

// Constructor Implementation
KnowledgeBaseBackward::KnowledgeBaseBackward() {
    // Initialize backward chaining rules
    // Example Rules:
    rules.emplace_back(make_unique<RuleBackward>(10, 
        unordered_map<string, string>{{"CHEST_PAIN", "YES"}, {"RADIATING_PAIN", "YES"}, {"EXERTION_STRESS", "YES"}, {"RELIEF_WITH_REST", "YES"}}, 
        "Coronary Artery Disease"));

    rules.emplace_back(make_unique<RuleBackward>(20, 
        unordered_map<string, string>{{"CHEST_PAIN", "YES"}, {"RADIATING_PAIN", "YES"}, {"EXERTION_STRESS", "YES"}, {"RELIEF_WITH_REST", "NO"}, {"NAUSEA_VOMITING", "YES"}}, 
        "Heart Attack (Myocardial Infarction)"));

    // ... Add all backward chaining rules here following the same pattern

    // Additional example rules:
    rules.emplace_back(make_unique<RuleBackward>(30, 
        unordered_map<string, string>{{"CHEST_PAIN", "YES"}, {"RADIATING_PAIN", "YES"}, {"EXERTION_STRESS", "YES"}, {"RELIEF_WITH_REST", "NO"}, {"NAUSEA_VOMITING", "NO"}, {"DISCOMFORT_OVER_MINUTES", "YES"}}, 
        "Heart Attack (Myocardial Infarction)"));

    rules.emplace_back(make_unique<RuleBackward>(40, 
        unordered_map<string, string>{{"CHEST_PAIN", "YES"}, {"RADIATING_PAIN", "YES"}, {"EXERTION_STRESS", "YES"}, {"RELIEF_WITH_REST", "NO"}, {"NAUSEA_VOMITING", "NO"}, {"DISCOMFORT_OVER_MINUTES", "NO"}, {"CHEST_PAIN_RANDOM", "YES"}}, 
        "Unstable Angina"));

    // Rule 50
    rules.emplace_back(make_unique<RuleBackward>(50, 
        unordered_map<string, string>{
        {"CHEST_PAIN", "YES"}, 
        {"RADIATING_PAIN", "YES"}, 
        {"EXERTION_STRESS", "YES"}, 
        {"RELIEF_WITH_REST", "NO"}, 
        {"NAUSEA_VOMITING", "NO"}, 
        {"DISCOMFORT_OVER_MINUTES", "NO"}, 
        {"CHEST_PAIN_RANDOM", "NO"} 
    }, 
    "Stable Angina"));

    // Rule 60
    rules.emplace_back(make_unique<RuleBackward>(60, 
        unordered_map<string, string>{
        {"CHEST_PAIN", "YES"}, 
        {"RADIATING_PAIN", "NO"}, 
        {"CHEST_PAIN_WORSE_LYING_DOWN", "YES"} 
    }, 
    "Pericarditis"));

// ... Continue adding all rules up to rule 380
}
