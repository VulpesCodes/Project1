//
// Created by iamaw on 10/3/2021.
//

#ifndef PROJECT1_STARTER_CODE_PARSER_H
#define PROJECT1_STARTER_CODE_PARSER_H

#include <vector>
#include "Token.h"
#include <iostream>
#include <fstream>

class Parser
{
private:
    std::vector<Token*> tokens;
    unsigned int index = 0;

    void parseDatalogProgram();

    void parseSchemeList();
    void parseFactList();
    void parseRuleList();
    void parseQueryList();

    void parseScheme();
    void parseFact();
    void parseRule();
    void parseQuery();

    void parseHeadPredicate();
    void parsePredicate();

    void parsePredicateList();
    void parseParameterList();
    void parseStringList();
    void parseIdList();
    void parseParameter();

    void checkSchemes();
    void checkColon();
    void checkFacts();
    void checkRules();
    void checkQueries();
    void checkID();
    void checkLeftParen();
    void checkRightParen();
    void checkColonDash();
    void checkString();
    void checkComma();
    void checkQMark();
    void checkEOF();
    void checkPeriod();

    void nextToken();
    Token* getToken();
    void removeComments();


    // TODO: add any other private methods here (if needed)

public:
    Parser();
    ~Parser();

    void Parse(std::vector<Token*>);
    //DatalogProgram parse();


    // TODO: add other public methods here

};

#endif //PROJECT1_STARTER_CODE_PARSER_H
