//
// Created by iamaw on 9/25/2021.
//

#ifndef PROJECT1_STARTER_CODE_LINECOMMENTAUTOMATON_H
#define PROJECT1_STARTER_CODE_LINECOMMENTAUTOMATON_H

#include "Automaton.h"

class LineCommentAutomaton : public Automaton
{
private:
    void S1(const std::string& input);


public:
    LineCommentAutomaton() : Automaton(TokenType::COMMENT) {}  // Call the base constructor

    void S0(const std::string& input);
};

#endif //PROJECT1_STARTER_CODE_LINECOMMENTAUTOMATON_H
