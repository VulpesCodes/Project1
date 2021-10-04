//
// Created by iamaw on 10/3/2021.
//

#ifndef PROJECT1_STARTER_CODE_DATALOGPROGRAM_H
#define PROJECT1_STARTER_CODE_DATALOGPROGRAM_H

#include <string>
#include <vector>
#include "Predicate.h"
#include "Rule.h"
#include "Parameter.h"

class DatalogProgram
{
private:
    std::vector<Predicate*> schemes;
    std::vector<Predicate*> facts;
    std::vector<Predicate*> queries;
    std::vector<Rule*> rules;


public:
    DatalogProgram();
    ~DatalogProgram();
    void addSchemes(Predicate*);
    void addFacts(Predicate*);
    void addQueries(Predicate*);
    void addRules(Rule*);
    std::string toString();
};


#endif //PROJECT1_STARTER_CODE_DATALOGPROGRAM_H
