#ifndef VARIABLELIST_H
#define VARIABLELIST_H

#include <string>
#include <unordered_map>

using namespace std;

class VariableList {
public:
    unordered_map<string, string> variables;

    bool isInstantiated(const string& var);
    void setVariable(const string& var, const string& value);
    string getVariable(const string& var);
    void printVariables();
};

#endif // VARIABLELIST_H
