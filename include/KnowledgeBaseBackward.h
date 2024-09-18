#ifndef KNOWLEDGEBASEBACKWARD_H
#define KNOWLEDGEBASEBACKWARD_H

#include "RuleBackward.h"
#include <vector>
#include <memory>

using namespace std;

class KnowledgeBaseBackward {
public:
    vector<unique_ptr<RuleBackward>> rules;

    KnowledgeBaseBackward();
};

#endif // KNOWLEDGEBASEBACKWARD_H
