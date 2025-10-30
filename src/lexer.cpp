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

        case '=': advance(); return makeToken(EQUAL);
        case ';': advance(); return makeToken(SEM);
        case '+': advance(); return makeToken(ADD);
        case '-': advance(); return makeToken(SUB);
        case '*': advance(); return makeToken(MUL);
        case '/': advance(); return makeToken(DIV);
    }

    if (std::isdigit(curr)) {
        std::string number;
        while (std::isdigit(peek())) number += advance();
        return makeToken(INT_LIT, number);
    }

    if (std::isalpha(curr) || curr == '_') {
        std::string word;
        while (std::isalnum(peek()) || peek() == '_')
            word += advance();

        if (word == "return") return makeToken(RETURN);
        return makeToken(UNK, word);
    }

    // Unknown character
    advance();
    std::string unknown(1, curr);
    return makeToken(UNK, unknown);
}
