#pragma once
#include <cstddef>
#include <optional>
#include <string>
#include <vector>
#include "./lexer.hpp"

  struct NodeExpr{
   Token token;
 };
  struct NodeExit{
    NodeExpr expr;
  };

class Parser {
  private:
  std::vector<Token> tokens;
  size_t position;
public:
explicit Parser(const std::vector<Token>& toks)
        : tokens(toks), position(0) {}
private:
Token peek() ;
    Token advance();
    Token makeToken(TokenType type, std::optional<std::string> value = std::nullopt);

};
