#include "Lexer.h"
#include "ColonAutomaton.h"
#include "ColonDashAutomaton.h"
#include "CommaAutomaton.h"
#include "PeriodAutomaton.h"
#include "QMarkAutomaton.h"
#include "LeftParenAutomaton.h"
#include "RightParenAutomaton.h"
#include "MultiplyAutomaton.h"
#include "AddAutomaton.h"
#include <iostream>
#include <fstream>

Lexer::Lexer() {
    CreateAutomata();
}

Lexer::~Lexer() {
    // TODO: need to clean up the memory in `automata` and `tokens`
}

void Lexer::CreateAutomata() {
    automata.push_back(new ColonAutomaton());
    automata.push_back(new ColonDashAutomaton());
    automata.push_back(new CommaAutomaton());
    automata.push_back(new PeriodAutomaton());
    automata.push_back(new QMarkAutomaton());
    automata.push_back(new LeftParenAutomaton());
    automata.push_back(new RightParenAutomaton());
    automata.push_back(new MultiplyAutomaton());
    automata.push_back(new AddAutomaton());

    // TODO: Add the other needed automata here
}

std::string Lexer::tokenstoString() {
    for (int i = 0; i < tokens.size(); i++) {
        std::cout << tokens[i]->toString()<< std::endl;
    }
    std::cout << "Total Tokens = " << tokens.size();
    return "";
}

std::string Lexer::descCreate(int value, std::string input) {
    std::string desc = "";
    for (int i = 0; i < value; i++) {
        desc += input[0];
        input.erase(0,1);
    }
    return desc;
}

void Lexer::Run(std::string& input) {
    // TODO: convert this pseudo-code with the algorithm into actual C++ code
    /*
    set lineNumber to 1
    // While there are more characters to tokenize
    loop while input.size() > 0 {
        set maxRead to 0
        set maxAutomaton to the first automaton in automata

        // TODO: you need to handle whitespace inbetween tokens

        // Here is the "Parallel" part of the algorithm
        //   Each automaton runs with the same input
        foreach automaton in automata {
            inputRead = automaton.Start(input)
            if (inputRead > maxRead) {
                set maxRead to inputRead
                set maxAutomaton to automaton
            }
        }
        // Here is the "Max" part of the algorithm
        if maxRead > 0 {
            set newToken to maxAutomaton.CreateToken(...)
                increment lineNumber by maxAutomaton.NewLinesRead()
                add newToken to collection of all tokens
        }
        // No automaton accepted input
        // Create single character undefined token
        else {
            set maxRead to 1
                set newToken to a  new undefined Token
                (with first character of input)
                add newToken to collection of all tokens
        }
        // Update `input` by removing characters read to create Token
        remove maxRead characters from input
    }
    add end of file token to all tokens
    */

    int lineNumber = 1;
    while (input.size() > 0) {
        int maxRead = 0;
        Automaton *maxAutomaton = automata[0];

        if (input[0] == ' ') {
            input.erase(0,1);
        }
        else if (input[0] == '\n')
        {
            lineNumber++;
            input.erase(0,1);
        }
        else if (input[0] == '\r')
        {
            input.erase(0,1);
        }
        else {
            for (int i = 0; i < automata.size(); i++) {
                int inputRead = automata[i]->Start(input);
                if (inputRead > maxRead) {
                    maxRead = inputRead;
                    maxAutomaton = automata[i];
                }
            }
            if (maxRead > 0) {
                Token *newToken = maxAutomaton->CreateToken(descCreate(maxRead, input), lineNumber);
                lineNumber += maxAutomaton->NewLinesRead();
                tokens.push_back(newToken);
            } else {
                maxRead = 1;
                Token *newToken = new Token(TokenType::UNDEFINED,descCreate(maxRead, input), lineNumber);
                tokens.push_back(newToken);
            }
            input.erase(0, maxRead);
        }

    }
    Token *newToken = new Token(TokenType::EOFILE,"", lineNumber);
    tokens.push_back(newToken);
    tokenstoString();
}
