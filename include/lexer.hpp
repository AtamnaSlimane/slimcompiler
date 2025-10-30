#pragma once
#include <optional>
#include <string>
#include <vector>
enum TokenType {
 RETURN,
 INT_LIT,
 SEM,
 E_O_F,
 ADD,
 SUB,
 MUL,
 DIV,
 EQUAL,
 UNK
};
struct Token {
  TokenType type;
  std::optional<std::string> value;
};
class Lexer {
private:
    std::string source;
    size_t position;
    size_t line;
    size_t column;

public:
    explicit Lexer(const std::string& src) 
        : source(src), position(0), line(1), column(1) {}
    
    Token nextToken();
    std::vector<Token> tokenize();
    
private:
    char peek() ;
    char advance();
    void skipWhitespace();
    Token makeToken(TokenType type, std::optional<std::string> value = std::nullopt);
};

