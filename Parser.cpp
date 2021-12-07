//
// Created by iamaw on 10/3/2021.
//

#include "Parser.h"


Parser::Parser() {

}

Parser::~Parser() {

}

void Parser::nextToken() {
    index += 1;
}

Token* Parser::getToken() {
    return tokens[index];
}

void Parser::removeComments() {
    while (index < tokens.size()) {
        if (getToken()->getType() == TokenType::COMMENT) {
            tokens.erase(tokens.begin()+index);
        }
        else {
            nextToken();
        }
    }
    index = 0;
}


DatalogProgram Parser::Parse(std::vector<Token*> tokenlist) {
    tokens = tokenlist;

    removeComments();
    try {
        datalog = parseDatalogProgram(datalog);
        //std::cout << "Success!" << std::endl;
        //std::cout << datalog.toString();
    }
    catch (Token* error) {
        //std::cout << "Failure!" << std::endl << "\t" << error->toString();
    }

    return datalog;
}
DatalogProgram Parser::parseDatalogProgram(DatalogProgram datalog) {
    std::vector<Predicate> schemes;
    std::vector<Predicate> facts;
    std::vector<Rule> rules;
    std::vector<Predicate> queries;
    checkSchemes();
    checkColon();
    datalog.addSchemes(parseScheme());
    schemes = parseSchemeList();
    checkFacts();
    checkColon();
    facts = parseFactList();
    checkRules();
    checkColon();
    rules = parseRuleList();
    checkQueries();
    checkColon();
    datalog.addQueries(parseQuery());
    queries = parseQueryList();
    checkEOF();
    for (unsigned int i = 0; i < schemes.size(); ++i) {
        datalog.addSchemes(schemes[i]);
    }
    for (unsigned int i = 0; i < facts.size(); ++i) {
        datalog.addFacts(facts[i]);
    }
    for (unsigned int i = 0; i < rules.size(); ++i) {
        datalog.addRules(rules[i]);
    }
    for (unsigned int i = 0; i < queries.size(); ++i) {
        datalog.addQueries(queries[i]);
    }

    return datalog;
}

std::vector<Predicate> Parser::parseSchemeList() {
    std::vector<Predicate> schemePredicates;
    if (getToken()->getType() == TokenType::ID) {
        schemePredicates.push_back(parseScheme());
        std::vector<Predicate> vector = parseSchemeList();
        for (unsigned int i = 0; i < vector.size(); ++i) {
            schemePredicates.push_back(vector[i]);
        }
    }
    return schemePredicates;
}
std::vector<Predicate> Parser::parseFactList() {
    std::vector<Predicate> factPredicates;
    if (getToken()->getType() == TokenType::ID) {
        factPredicates.push_back(parseFact());
        std::vector<Predicate> vector = parseFactList();
        for (unsigned int i = 0; i < vector.size(); ++i) {
            factPredicates.push_back(vector[i]);
        }
    }
    return factPredicates;
}
std::vector<Rule> Parser::parseRuleList() {
    std::vector<Rule> Rules;
    if (getToken()->getType() == TokenType::ID) {
        Rules.push_back(parseRule());
        std::vector<Rule> vector = parseRuleList();
        for (unsigned int i = 0; i < vector.size(); ++i) {
            Rules.push_back(vector[i]);
        }
    }
    return Rules;
}
std::vector<Predicate> Parser::parseQueryList() {
    std::vector<Predicate> queryPredicates;
    if (getToken()->getType() == TokenType::ID) {
        queryPredicates.push_back(parseQuery());
        std::vector<Predicate> vector = parseQueryList();
        for (unsigned int i = 0; i < vector.size(); ++i) {
            queryPredicates.push_back(vector[i]);
        }
    }
    return queryPredicates;
}

Predicate Parser::parseScheme() {
    Predicate predicate;
    predicate.setID(checkID().toString());
    checkLeftParen();
    predicate.addParameter(checkID());
    std::vector<Parameter> paramList = parseIdList();
    checkRightParen();
    for (unsigned int i = 0; i < paramList.size(); ++i) {
        predicate.addParameter(paramList[i]);
    }
    return predicate;
/*
    checkID();
    checkLeftParen();
    checkID();
    parseIdList();
    checkRightParen();
    */
}
Predicate Parser::parseFact() {
    Predicate predicate;
    predicate.setID(checkID().toString());
    checkLeftParen();
    predicate.addParameter(checkString());
    std::vector<Parameter> paramList = parseStringList();
    checkRightParen();
    checkPeriod();
    for (unsigned int i = 0; i < paramList.size(); ++i) {
        predicate.addParameter(paramList[i]);
    }
    return predicate;
}
Rule Parser::parseRule() {
    Rule rule;
    rule.setHeadPredicate(parseHeadPredicate());
    checkColonDash();
    rule.addPredicates(parsePredicate());
    std::vector<Predicate> predList = parsePredicateList();
    for (unsigned int i = 0; i < predList.size(); ++i) {
        rule.addPredicates(predList[i]);
    }
    checkPeriod();
    return rule;
}
Predicate Parser::parseQuery() {
    Predicate predicate;
    predicate = parsePredicate();
    checkQMark();
    return predicate;
}

Predicate Parser::parseHeadPredicate() {
    Predicate predicate;
    predicate.setID(checkID().toString());
    checkLeftParen();
    predicate.addParameter(checkID());
    std::vector<Parameter> paramList =parseIdList();
    checkRightParen();
    for (unsigned int i = 0; i < paramList.size(); ++i) {
        predicate.addParameter(paramList[i]);
    }
    return predicate;
}
Predicate Parser::parsePredicate() {
    Predicate predicate;
    predicate.setID(checkID().toString());
    checkLeftParen();
    predicate.addParameter(parseParameter());
    std::vector<Parameter> paramList = parseParameterList();
    checkRightParen();
    for (unsigned int i = 0; i < paramList.size(); ++i) {
        predicate.addParameter(paramList[i]);
    }
    return predicate;
}

std::vector<Predicate> Parser::parsePredicateList() {
    std::vector<Predicate> vector;
    if (getToken()->getType() == TokenType::COMMA) {
        checkComma();
        Predicate first = parsePredicate();
        vector = parsePredicateList();
        vector.insert(vector.begin(),first);
    }
    return vector;
}
std::vector<Parameter> Parser::parseParameterList() {
    if (getToken()->getType() == TokenType::COMMA) {
        checkComma();
        Parameter id = parseParameter();
        std::vector<Parameter> vector = parseParameterList();
        vector.insert(vector.begin(),id);
        return vector;
    }
    std::vector<Parameter> vector;
    return vector;
}
std::vector<Parameter> Parser::parseStringList() {
    if (getToken()->getType() == TokenType::COMMA) {
        checkComma();
        Parameter id = checkString();
        std::vector<Parameter> vector = parseStringList();
        vector.insert(vector.begin(),id);
        return vector;
    }
    std::vector<Parameter> vector;
    return vector;
}
std::vector<Parameter> Parser::parseIdList() {
    if (getToken()->getType() == TokenType::COMMA) {
        checkComma();
        Parameter id = checkID();
        std::vector<Parameter> vector = parseIdList();
        vector.insert(vector.begin(),id);
        return vector;
    }
    std::vector<Parameter> vector;
    return vector;
}
Parameter Parser::parseParameter() {
    if (getToken()->getType() == TokenType::STRING) {
        return checkString();
    }
    else if (getToken()->getType() == TokenType::ID) {
        return checkID();
    }
    else {
        throw getToken();
    }
}




void Parser::checkSchemes() {
    if (getToken()->getType() == TokenType::SCHEMES) {
        nextToken();
    }
    else {
        throw getToken();
    }
}
void Parser::checkColon() {
    if (getToken()->getType() == TokenType::COLON) {
        nextToken();
    }
    else {
        throw getToken();
    }
}
void Parser::checkFacts() {
    if (getToken()->getType() == TokenType::FACTS) {
        nextToken();
    }
    else {
        throw getToken();
    }
}
void Parser::checkRules() {
    if (getToken()->getType() == TokenType::RULES) {
        nextToken();
    }
    else {
        throw getToken();
    }
}
void Parser::checkQueries() {
    if (getToken()->getType() == TokenType::QUERIES) {
        nextToken();
    }
    else {
        throw getToken();
    }
}
Parameter Parser::checkID() {
    if (getToken()->getType() == TokenType::ID) {
        Parameter id;
        id.setString(getToken()->getDesc());
        nextToken();
        return id;

    }
    else {
        throw getToken();
    }
}
void Parser::checkLeftParen() {
    if (getToken()->getType() == TokenType::LEFT_PAREN) {
        nextToken();
    }
    else {
        throw getToken();
    }
}
void Parser::checkRightParen() {
    if (getToken()->getType() == TokenType::RIGHT_PAREN) {
        nextToken();
    }
    else {
        throw getToken();
    }
}
void Parser::checkColonDash() {
    if (getToken()->getType() == TokenType::COLON_DASH) {
        nextToken();
    }
    else {
        throw getToken();
    }
}
Parameter Parser::checkString() {
    if (getToken()->getType() == TokenType::STRING) {
        Parameter string;
        string.setString(getToken()->getDesc());
        nextToken();
        return string;

    }
    else {
        throw getToken();
    }
}
void Parser::checkComma() {
    if (getToken()->getType() == TokenType::COMMA) {
        nextToken();
    }
    else {
        throw getToken();
    }
}
void Parser::checkQMark() {
    if (getToken()->getType() == TokenType::Q_MARK) {
        nextToken();
    }
    else {
        throw getToken();
    }
}
void Parser::checkEOF() {
    if (getToken()->getType() == TokenType::EOFILE) {
        nextToken();
    }
    else {
        throw getToken();
    }
}

void Parser::checkPeriod() {
    if (getToken()->getType() == TokenType::PERIOD) {
        nextToken();
    }
    else {
        throw getToken();
    }
}

DatalogProgram Parser::getDatalog() {
    return datalog;
}
