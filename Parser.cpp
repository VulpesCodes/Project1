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


void Parser::Parse(std::vector<Token*> tokenlist) {
    tokens = tokenlist;
    removeComments();
    try {
        parseDatalogProgram();
        std::cout << "Success!";
    }
    catch (Token* error) {
        std::cout << "Failure!" << std::endl << "\t" << error->toString();
    }


}
void Parser::parseDatalogProgram() {
    checkSchemes();
    checkColon();
    parseScheme();
    parseSchemeList();
    checkFacts();
    checkColon();
    parseFactList();
    checkRules();
    checkColon();
    parseRuleList();
    checkQueries();
    checkColon();
    parseQuery();
    parseQueryList();
    checkEOF();
}

void Parser::parseSchemeList() {
    if (getToken()->getType() == TokenType::ID) {
        parseScheme();
        parseSchemeList();
    }
}
void Parser::parseFactList() {
    if (getToken()->getType() == TokenType::ID) {
        parseFact();
        parseFactList();
    }
}
void Parser::parseRuleList() {
    if (getToken()->getType() == TokenType::ID) {
        parseRule();
        parseRuleList();
    }
}
void Parser::parseQueryList() {
    if (getToken()->getType() == TokenType::ID) {
        parseQuery();
        parseQueryList();
    }
}

void Parser::parseScheme() {
    checkID();
    checkLeftParen();
    checkID();
    parseIdList();
    checkRightParen();
}
void Parser::parseFact() {
    checkID();
    checkLeftParen();
    checkString();
    parseStringList();
    checkRightParen();
    checkPeriod();
}
void Parser::parseRule() {
    parseHeadPredicate();
    checkColonDash();
    parsePredicate();
    parsePredicateList();
    checkPeriod();
}
void Parser::parseQuery() {
    parsePredicate();
    checkQMark();
}

void Parser::parseHeadPredicate() {
    checkID();
    checkLeftParen();
    checkID();
    parseIdList();
    checkRightParen();
}
void Parser::parsePredicate() {
    checkID();
    checkLeftParen();
    parseParameter();
    parseParameterList();
    checkRightParen();
}

void Parser::parsePredicateList() {
    if (getToken()->getType() == TokenType::COMMA) {
        checkComma();
        parsePredicate();
        parsePredicateList();
    }
}
void Parser::parseParameterList() {
    if (getToken()->getType() == TokenType::COMMA) {
        checkComma();
        parseParameter();
        parseParameterList();
    }
}
void Parser::parseStringList() {
    if (getToken()->getType() == TokenType::COMMA) {
        checkComma();
        checkString();
        parseStringList();
    }
}
void Parser::parseIdList() {
    if (getToken()->getType() == TokenType::COMMA) {
        checkComma();
        checkID();
        parseIdList();
    }
}
void Parser::parseParameter() {
    if (getToken()->getType() == TokenType::STRING) {
        checkString();
    }
    else if (getToken()->getType() == TokenType::ID) {
        checkID();
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
void Parser::checkID() {
    if (getToken()->getType() == TokenType::ID) {
        nextToken();
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
void Parser::checkString() {
    if (getToken()->getType() == TokenType::STRING) {
        nextToken();
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