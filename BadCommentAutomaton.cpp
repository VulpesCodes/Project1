//
// Created by iamaw on 9/25/2021.
//

#include "BadCommentAutomaton.h"

void BadCommentAutomaton::S0(const std::string& input) {
    if(input[index] == '#') {
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void BadCommentAutomaton::S1(const std::string& input) {
    if (input[index] == '|') {
        inputRead++;
        index++;
        S2(input);
    }

    else {
        Serr();
    }
}

void BadCommentAutomaton::S2(const std::string& input) {
    if (index >= input.size()) {

    }
    else if (input[index] == '|' and input[index+1] == '#') {
        Serr();
    }
    else if (input[index] == '\n') {
        newLines++;
        index++;
        inputRead++;
        S2(input);
    }
    else {
        inputRead++;
        index++;
        S2(input);
    }
}
