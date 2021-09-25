//
// Created by iamaw on 9/25/2021.
//

#include "BadStringAutomaton.h"


void BadStringAutomaton::S0(const std::string& input) {
    if(input[index] == '\'') {
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void BadStringAutomaton::S1(const std::string& input) {
    if (index >= input.size() ) {

    }
    else if (input[index] == '\'' and input[index+1] == '\'') {
        inputRead++;
        index++;
        inputRead++;
        index++;
        S1(input);
    }
    else if (input[index] == '\n') {
        inputRead++;
        index++;
        newLines++;
        S1(input);
    }
    else if (input[index] == '\'' and input[index+1] != '\'') {
        Serr();
    }
    else {
        inputRead++;
        index++;
        S1(input);
    }
}

