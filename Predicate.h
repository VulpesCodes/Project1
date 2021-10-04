//
// Created by iamaw on 10/4/2021.
//

#ifndef PROJECT1_STARTER_CODE_PREDICATE_H
#define PROJECT1_STARTER_CODE_PREDICATE_H

#include <string>
#include <vector>
#include "Parameter.h"

class Predicate
{
private:
    std::string id;
    std::vector<Parameter*> parameters;



public:
    Predicate();
    ~Predicate();
    void setID(std::string);
    void addParameter(Parameter*);
    std::string toString();
};

#endif //PROJECT1_STARTER_CODE_PREDICATE_H
