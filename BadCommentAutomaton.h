//
// Created by iamaw on 9/25/2021.
//

#ifndef PROJECT1_STARTER_CODE_BADCOMMENTAUTOMATON_H
#define PROJECT1_STARTER_CODE_BADCOMMENTAUTOMATON_H

#include "Automaton.h"

class BadCommentAutomaton : public Automaton
{
private:
    void S1(const std::string& input);
    void S2(const std::string& input);



public:
    BadCommentAutomaton() : Automaton(TokenType::UNDEFINED) {}  // Call the base constructor

    void S0(const std::string& input);
};

#endif //PROJECT1_STARTER_CODE_BADCOMMENTAUTOMATON_H
