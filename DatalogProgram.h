//
// Created by iamaw on 10/3/2021.
//

#ifndef PROJECT1_STARTER_CODE_DATALOGPROGRAM_H
#define PROJECT1_STARTER_CODE_DATALOGPROGRAM_H

#include <string>
#include <vector>
#include <set>
#include "Predicate.h"
#include "Rule.h"
#include "Parameter.h"


class DatalogProgram
{
private:
    std::vector<Predicate> schemes;
    std::vector<Predicate> facts;
    std::vector<Predicate> queries;
    std::vector<Rule> rules;
    std::vector<Parameter> domain;
    std::vector<Parameter> createDomain();


public:
    DatalogProgram();
    ~DatalogProgram();
    void addSchemes(Predicate);
    void addFacts(Predicate);
    void addQueries(Predicate);
    void addRules(Rule);
    std::string toString();

    std::vector<Predicate> getSchemes();
    std::vector<Predicate> getFacts();
    std::vector<Predicate> getQueries();
    std::vector<Rule> getRules();
};


#endif //PROJECT1_STARTER_CODE_DATALOGPROGRAM_H
