#ifndef TOKEN_H
#define TOKEN_H
#include <string>


enum class TokenType {
    COLON,
    COLON_DASH,
    COMMA,
    PERIOD,
    Q_MARK,
    LEFT_PAREN,
    RIGHT_PAREN,
    MULTIPLY,
    ADD,
    SCHEMES,
    FACTS,
    RULES,
    QUERIES,
    ID,
    STRING,
    COMMENT,
    UNDEFINED,
    EOFILE
};

class Token
{
private:
    // TODO: add member variables for information needed by Token
    std::string description;
    int lineNumber;
    TokenType tokenName;


public:
    Token();
    std::string TokenTypeToString(TokenType type);
    std::string toString(void);
    TokenType getType();
    // TODO: add other needed methods
    Token(TokenType type ,std::string basicString, int i);
};

#endif // TOKEN_H

