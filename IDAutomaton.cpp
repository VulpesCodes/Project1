//
// Created by iamaw on 9/24/2021.
//

#include "IDAutomaton.h"
#include <cctype>

void IDAutomaton::S0(const std::string& input) {
    if (std::isalpha(input[index]) and (std::isalpha(input[index+1]) or std::isalnum(input[index+1]))) {
        inputRead++;
        index++;
        S1(input);
    }
    else if ( std::isalpha(input[index])) {
        inputRead++;
    }
    else {
        Serr();
    }
}

void IDAutomaton::S1(const std::string& input) {
    if ((std::isalpha(input[index]) or std::isalnum(input[index]))   and   (std::isalpha(input[index+1]) or std::isalnum(input[index+1]))) {
        inputRead++;
        index++;
        S1(input);
    }
    else if ((std::isalpha(input[index]) or std::isalnum(input[index]))) {
        inputRead++;
    }
    else {
        Serr();
    }
}