#include "Token.h"

Token::Token() {
    // TODO: initialize all member variables
}
std::string Token::TokenTypeToString(TokenType type){
    switch (type) {
        case TokenType::COLON: return "COLON"; break;
        case TokenType::COLON_DASH: return "COLON_DASH"; break;
        case TokenType::UNDEFINED: return "UNDEFINED"; break;
    }
}
std::string Token::toString() {
    std::string newtype = TokenTypeToString(type)
    return "(" +
}



