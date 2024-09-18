#ifndef KNOWLEDGEBASEFORWARD_H
#define KNOWLEDGEBASEFORWARD_H

#include "RuleForward.h"
#include <vector>
#include <memory>

using namespace std;

class KnowledgeBaseForward {
public:
    vector<unique_ptr<RuleForward>> rules;

    KnowledgeBaseForward();
};

#endif // KNOWLEDGEBASEFORWARD_H
