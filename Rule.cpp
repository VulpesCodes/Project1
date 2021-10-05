//
// Created by iamaw on 10/4/2021.
//

#include "Rule.h"

Rule::Rule() {

}

Rule::~Rule() {

}

void Rule::setHeadPredicate(Predicate input) {
    headPredicate = input;
}

void Rule::addPredicates(Predicate input) {
    bodyPredicates.push_back(input);
}

std::string Rule::toString() {
    std::string output = "";
    output += headPredicate.toString() + " :- ";
    for (unsigned int i = 0; i < bodyPredicates.size(); ++i) {
        if (i != 0) {
            output += ",";
        }
        output += bodyPredicates[i].toString();

    }
    output += ".";
    return output;
}

