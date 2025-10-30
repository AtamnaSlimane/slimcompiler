#include <iostream>
#include <cctype>
#include <string>
#include "../include/lexer.hpp"

char Lexer::peek() {
    if (position >= source.length()) return '\0';
    return source[position];
}

char Lexer::advance() {
    if (position >= source.length()) return '\0';
    char c = source[position++];
    if (c == '\n') {
        line++;
        column = 1;
    } else {
        column++;
    }
    return c;
}

void Lexer::skipWhitespace() {
    while (std::isspace(peek())) {
        advance();
    }
}

Token Lexer::makeToken(TokenType type, std::optional<std::string> value) {
    return Token{ type, value };
}
Token Lexer::nextToken() {
    skipWhitespace();
    char curr = peek();

    if (curr == '\0')
        return makeToken(E_O_F);

    switch (curr) {
        case '=': advance(); return makeToken(ASSIGN);
        case '+': advance(); return makeToken(PLUS);
        case '*': advance(); return makeToken(STAR);
        case '/': advance(); return makeToken(SLASH);
        case ',': advance(); return makeToken(COMMA);
        case ';': advance(); return makeToken(SEMICOLON);
        case '(': advance(); return makeToken(LPAREN);
        case ')': advance(); return makeToken(RPAREN);
        case '{': advance(); return makeToken(LSQUIRLY);
        case '}': advance(); return makeToken(RSQUIRLY);
    }

    if (std::isdigit(curr)) {
        std::string number;
        while (std::isdigit(peek())) number += advance();
        return makeToken(INT_LIT, number);
    }

    if (std::isalpha(curr) || curr == '_') {
        std::string ident;
        while (std::isalnum(peek()) || peek() == '_')
            ident += advance();

        if (ident == "function") return makeToken(FUNCTION);
        if (ident == "let") return makeToken(LET);
        return makeToken(IDENT, ident);
    }

    // Unknown character
    advance();
    std::string unknown(1, curr);
    return makeToken(ILLEGAL, unknown);
}

