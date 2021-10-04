//
// Created by iamaw on 10/4/2021.
//

#include "Predicate.h"

Predicate::Predicate() {

}

Predicate::~Predicate() {

}

void Predicate::setID(std::string input) {
    id=input;
}

void Predicate::addParameter(Parameter * input) {
    parameters.push_back(input);
}

std::string Predicate::toString() {
    std::string output = "";
    output += id + "(";
    for (unsigned int i = 0; i < parameters.size(); ++i) {
        if (i != 0) {
            output += ",";
        }
        output += parameters[i]->toString();

    }
    output += ")";
    return output;
}
