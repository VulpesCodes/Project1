//
// Created by iamaw on 9/25/2021.
//

#ifndef PROJECT1_STARTER_CODE_BLOCKCOMMENT_H
#define PROJECT1_STARTER_CODE_BLOCKCOMMENT_H

#include "Automaton.h"

class BlockCommentAutomaton : public Automaton
{
private:
    void S1(const std::string& input);
    void S2(const std::string& input);


public:
    BlockCommentAutomaton() : Automaton(TokenType::COMMENT) {}  // Call the base constructor

    void S0(const std::string& input);
};

#endif //PROJECT1_STARTER_CODE_BLOCKCOMMENT_H
