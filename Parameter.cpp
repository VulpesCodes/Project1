//
// Created by iamaw on 10/4/2021.
//

#include "Parameter.h"

Parameter::Parameter() {

}

Parameter::Parameter(std::string input) {
    setString(input);
}

Parameter::~Parameter() {

}

std::string Parameter::toString() {
    return description;
}

void Parameter::setString(std::string input) {
    description = input;
}
