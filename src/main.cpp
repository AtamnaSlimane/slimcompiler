#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "../include/lexer.hpp"

int main() {
    std::ifstream file("try/ex.slim");
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file try/ex.slim\n";
        return 1;
    }

    // Read the entire file content into a string
    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string code = buffer.str();
    file.close();

    Lexer lexer(code);
    Token token;

    do {
        token = lexer.nextToken();

        std::cout << "Token: ";

        switch (token.type) {
            case RETURN: std::cout << "RETURN"; break;
            case INT_LIT: std::cout << "INT_LIT"; break;
            case ADD: std::cout << "ADD"; break;
            case SUB: std::cout << "SUB"; break;
            case MUL: std::cout << "MUL"; break;
            case DIV: std::cout << "DIV"; break;
            case SEM: std::cout << "SEM"; break;
            case EQUAL: std::cout << "EQUAL"; break;
            case E_O_F: std::cout << "EOF"; break;
            case UNK: std::cout << "UNK"; break;
            default: std::cout << "???"; break;
        }

        if (token.value.has_value()) {
            std::cout << " (" << token.value.value() << ")";
        }

        std::cout << std::endl;

    } while (token.type != E_O_F);

    return 0;
}
