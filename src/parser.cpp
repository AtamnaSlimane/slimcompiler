#include <iostream>
#include <cctype>
#include <optional>
#include <string>
#include <stdexcept>
#include "../include/lexer.hpp"
#include "../include/parser.hpp"
Token Parser::peek(){
  if (position >= tokens.size()) {
  return {E_O_F,std::nullopt};  
  }
  else {
  return tokens[position];
  }
}
Token Parser::advance(){
  if (peek().type != E_O_F) {
  position++;
  }
  return tokens[position-1];
}

