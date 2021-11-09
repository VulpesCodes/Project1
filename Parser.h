//
// Created by iamaw on 10/3/2021.
//

#ifndef PROJECT1_STARTER_CODE_PARSER_H
#define PROJECT1_STARTER_CODE_PARSER_H

#include <vector>
#include "Token.h"
#include <iostream>
#include <fstream>
#include "DatalogProgram.h"


class Parser
{
private:
    std::vector<Token*> tokens;
    unsigned int index = 0;
    DatalogProgram datalog;

    DatalogProgram parseDatalogProgram(DatalogProgram);

    std::vector<Predicate> parseSchemeList();
    std::vector<Predicate> parseFactList();
    std::vector<Rule> parseRuleList();
    std::vector<Predicate> parseQueryList();

    Predicate parseScheme();
    Predicate parseFact();
    Rule parseRule();
    Predicate parseQuery();

    Predicate parseHeadPredicate();
    Predicate parsePredicate();

    std::vector<Predicate> parsePredicateList();
    std::vector<Parameter> parseParameterList();
    std::vector<Parameter> parseStringList();
    std::vector<Parameter> parseIdList();
    Parameter parseParameter();

    void checkSchemes();
    void checkColon();
    void checkFacts();
    void checkRules();
    void checkQueries();
    Parameter checkID();
    void checkLeftParen();
    void checkRightParen();
    void checkColonDash();
    Parameter checkString();
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

    DatalogProgram Parse(std::vector<Token*>);
    //DatalogProgram parse();
    DatalogProgram getDatalog();


    // TODO: add other public methods here

};

#endif //PROJECT1_STARTER_CODE_PARSER_H
