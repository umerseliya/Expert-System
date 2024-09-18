#include "VariableList.h"
#include <iostream>

// Check if a variable is instantiated
bool VariableList::isInstantiated(const string& var) {
    return variables.find(var) != variables.end();
}

// Set variable value
void VariableList::setVariable(const string& var, const string& value) {
    variables[var] = value;
}

// Get variable value
string VariableList::getVariable(const string& var) {
    if(isInstantiated(var))
        return variables[var];
    else
        return "";
}

// Print all variables and their values
void VariableList::printVariables() {
    cout << "Variable List:\n";
    for(auto& pair : variables){
        cout << pair.first << " = " << pair.second << "\n";
    }
}
