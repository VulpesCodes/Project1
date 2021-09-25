//
// Created by iamaw on 9/25/2021.
//

#include "LineCommentAutomaton.h"


void LineCommentAutomaton::S0(const std::string& input) {
    if(input[index] == '#' and input[index+1] != '|') {
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void LineCommentAutomaton::S1(const std::string& input) {
    if (input[index] == '\n') {

    }
    else if (input[index] == '\r') {

    }
    else if (index >= input.size()){

    }
    else {
        inputRead++;
        index++;
        S1(input);
    }
}

