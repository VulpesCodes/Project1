#include "Token.h"

Token::Token() {
    tokenName = TokenType::UNDEFINED;
    description = "";
    lineNumber = 0;
}
std::string Token::TokenTypeToString(TokenType type){
    switch (type) {
        case TokenType::COLON: return "COLON"; break;
        case TokenType::COLON_DASH: return "COLON_DASH"; break;
        case TokenType::UNDEFINED: return "UNDEFINED"; break;
    }
}

Token::Token(TokenType type,std::string input, int i) {
    tokenName = type;
    description = input;
    lineNumber = i;
}

std::string Token::toString() {
    return "(" + TokenTypeToString(tokenName) + ",\"" + description + "\"," + std::to_string(lineNumber) + ")";
}




