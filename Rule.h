//
// Created by iamaw on 10/4/2021.
//

#ifndef PROJECT1_STARTER_CODE_RULE_H
#define PROJECT1_STARTER_CODE_RULE_H

#include <string>
#include <vector>
#include "Parameter.h"
#include "Predicate.h"

class Rule
{
private:
    Predicate headPredicate;
    std::vector<Predicate> bodyPredicates;


public:
    Rule();
    ~Rule();
    void setHeadPredicate(Predicate);
    void addPredicates(Predicate);
    std::string toString();
};

#endif //PROJECT1_STARTER_CODE_RULE_H
