//
// Created by iamaw on 9/25/2021.
//

#include "BlockComment.h"

void BlockCommentAutomaton::S0(const std::string& input) {
    if(input[index] == '#') {
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void BlockCommentAutomaton::S1(const std::string& input) {
    if (input[index] == '|') {
        inputRead++;
        index++;
        S2(input);
    }
    else {
        Serr();
    }
}

void BlockCommentAutomaton::S2(const std::string& input) {
    if (index >= input.size()) {
        Serr();
    }
    else if (input[index] == '|' and input[index+1] == '#') {
        inputRead++;
        inputRead++;

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
