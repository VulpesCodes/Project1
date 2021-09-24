#ifndef TOKEN_H
#define TOKEN_H
#include <string>

enum class TokenType {
    COLON,
    COLON_DASH,
    // TODO: add the other types of tokens
    UNDEFINED
};

class Token
{
private:
    // TODO: add member variables for information needed by Token
    std::string description;


public:
    Token();
    std::string TokenTypeToString(TokenType type);
    std::string toString(void);
    // TODO: add other needed methods
};

#endif // TOKEN_H

